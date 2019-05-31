/*
*@author: Aplomb Huang
*@V#:00800816
*@Class: CMSC 257 Spring 17
*@Assignment #2
*@built date: March 22th, 2017
*@description: This is where the functions are implemented
*/

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include <math.h>
#include <stdlib.h>
#include<cmsc257-s17-assign2-support.h>



struct block_meta // This is a structure that occupies a little memory and record how big the size is of the malloc
{
 size_t size;
 struct block_meta *next;
 int free;
 //int magic;  for debugging, remove if non-debug mode
};

#define META_SIZE sizeof(struct block_meta)

void *global_base = NULL;



struct block_meta *find_free_block(struct block_meta **last, size_t size)// this structure finds a large enough block of memory to free up
{
  struct block_meta *current = global_base;

  while(current && !(current -> free && current -> size >= size))
    {*last = current;  current = current->next;}

 struct block_meta *compare = current;

   if(compare != NULL)
	{
          while(current != NULL){
		do
    		{*last = current;  current = current->next; }
		while(current && !(current -> free && current -> size >= size));

		if((compare->size >= current->size) && (current != NULL)){compare = current;} //this implementation is the best fit algorithm instead of the first fit, it continue to search the available block and provide the smallest possible fit
             }

	current = compare;
	}

  return current;
}



struct block_meta *request_space(struct block_meta* last, size_t size) // this structure request free space from heap  using sbrk and add the space at the end of the linked list.
{ struct block_meta *block;
  block = sbrk(0);
  void *request = sbrk(size + META_SIZE);
  assert((void*)block == request); // Not thread safe.
  if(request == (void*) -1) {return NULL;}// sbrk failed.

  if (last) {last -> next = block;}//NULL on first request.

  block->size = size;
  block->next = NULL;
  block->free = 0;
  //block->magic = 0x12345678;
  return block;
}

void *malloc(size_t size)
{
  struct block_meta *block;
  if (size <= 0){return NULL;} // if the user entered wrong data for size.

  //the following code is addition to tutorial
  size = (size + META_SIZE) + (8-(size+META_SIZE)%8); //size%8 would get the difference between size and 8,
    // size of the block meta is also counted into the total block size
  //this is to to allocate a block of memory aligning the machine memory size.


  if (!global_base)// if global base is null, request space and set base pointer to new block
  { block = request_space(NULL, size);
     if(!block) {return NULL;} // No space for block.

    global_base = block;

  }
  else // if global base is not null, then we check to see if we can reuse any existing space
  {
   struct block_meta *last = global_base;
   block = find_free_block(&last, size);
     if(!block){// fail to find free block
	   block = request_space(last, size);

            if(!block){return NULL;} //both failed
	}
     else// block found
      {block->free = 0;
      // block->magic = 0x7777777;
      // magic is a number that separate the rest of the free memory or consider splitting the block
      // the following code is to split the available memory block to a exact fit and the remaining memory would be free
        size = size + META_SIZE +8; // this is to make sure the available space is enough to fit in current request plus to construct a new block. and +8 is the minimum size for a block(an int);
      if(block->size >= size)
        {void * ptr = block + (size - META_SIZE -8) ;// this is the pointer address for the new block, by calculating how much memory to count from current pointer to the new pointer.
           struct block_meta *new_block = ptr;
	   new_block->next = block->next;
           block -> next = ptr;
	   new_block->free = 1;
	   new_block->size = 8;
	   block->size = (size -META_SIZE- META_SIZE -8);
	   block->free = 0;
        }


      }

  }

 return(block+1);// since block is a pointer, incrementing one gives the address to the region after the block meta

}

struct block_meta *get_block_ptr(void *ptr){return (struct block_meta*)ptr -1;} // to get address of actual data storage in multiple places


void *calloc(size_t nelem, size_t elsize)
{
  size_t size = nelem * elsize; // over flow not check yet
  void *ptr = malloc(size);
  memset(ptr, 0, size);
  return ptr;

}

void *realloc(void *ptr, size_t size)
{ if (size <= 0){return NULL;} // if the user entered wrong data for size.

  //the following code is addition to tutorial
  size = (size + META_SIZE) + (8-(size+META_SIZE)%8);

  if(!ptr){return malloc(size);}//Null ptr. realloc should act like malloc.

  struct block_meta* block_ptr = get_block_ptr(ptr);
   if(block_ptr -> size >= size)
   {size = size + META_SIZE +8; // this is to make sure the available space is enough to fit in current request plus to construct a new block. and +8 is the minimum size for a block(an int);
      if(block_ptr->size >= size)
        {void * newBlock_ptr = block_ptr + (size - META_SIZE -8) ;// this is the pointer address for the new block, by calculating how much memory to count from current pointer to the new pointer.
           struct block_meta *new_block = newBlock_ptr;
	   new_block->next = block_ptr->next;
           block_ptr -> next = newBlock_ptr;
	   new_block->free = 0;
	   new_block->size = 8;
	   block_ptr->size =(size - META_SIZE- META_SIZE -8);
	   block_ptr->free = 0;
	   free(newBlock_ptr);
        }

	return block_ptr;} // if we have enough space then free some space with split.
   // then ptr doesn't have enough space, reallocation finds new space
   void *new_ptr;
   new_ptr = malloc(size);//need to realloc. Malloc new space and free old space.
   if(!new_ptr){return NULL;}// set errno on failure;
   memcpy(new_ptr, ptr, block_ptr -> size);// then copy old data to new space.
   free(ptr);
   return new_ptr;

}

void free(void *ptr)
{
  if(!ptr){return;}
  struct block_meta* block_ptr = get_block_ptr(ptr);
  assert(block_ptr -> free == 0);
  //assert(block_ptr -> magic == 0x77777777 || block_ptr -> magic == 0x12345678);
  block_ptr -> free = 1;
 // block_ptr -> magic = 0x55555555;
 //the following code is trying to merge consecutive free blocks
 short int check = 1;//this variable serves as boolean

 while(check != 0){
 if(block_ptr->next != NULL) //see if its the end of the list, if not continue next step
 {
       // block_ptr = block_ptr->next;set block to the next available block on the list
        if(block_ptr ->next-> free == 1)//check if next block is free
           {  block_ptr->size += block_ptr->next->size + META_SIZE ;// add up the sizes of 2 free blocks
               if(block_ptr->next->next != NULL){// if the there's another block after the next block
               block_ptr->next = block_ptr->next->next;//link to the next next block's address
               // and the whole while codes would loop to merge more free blocks if there's any
                  }      // when there's no next next block
              else{ block_ptr->next = NULL; check = 0;} // next pointer can become null, exit loop
           }
        else{check = 0;}  //block not free, exit loop

 }else{check = 0;}// end of block list,
 }

}
