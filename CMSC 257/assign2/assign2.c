/*
*@author: Aplomb Huang
*@V#:00800816
*@Class: CMSC 257 Spring 17
*@Assignment #2
*@built date: March 18th, 2017
*@citation: a quick tutorial on implementing and debugging malloc, free, calloc, and realloc
*           from website: http://danluu.com/malloc-tutorial/
*/

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

void *malloc(size_t size);
void *calloc(size_t nelem, size_t elsize);
void *realloc(void *ptr, size_t size);
void free(void *ptr);



int main(void)
{
  void *heap_bottom = sbrk(0); // This saves where the heap is before we begin any operation

  void *memory_count = 0x0;

 printf("the following malloc operation is for type float. \n");

 float *arr1 = (float *)malloc(15*sizeof(float));

  if(arr1 == NULL){printf("Failed to allocate memory.\n");}// in case of allocation failed.

  void *heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);


printf("the following malloc operation is for type int. \n");

int *arr2 = (int *)malloc(10*sizeof(int));

    if(arr2 == NULL){printf("Failed to allocate memory.\n");}

    heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);


printf("the following malloc  operation is for type char. \n");

char *arr3 = (char *)malloc(25*sizeof(char));

    if(arr3 == NULL){printf("Failed to allocate memory.\n");}

   heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);


printf("the following malloc operation is for type double. \n ");

double *arr4 = (double *)malloc(10*sizeof(double));

    if(arr4 == NULL){printf("Failed to allocate memory.\n");}

   heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);



printf("the following malloc  operation is for type long. \n ");

long *arr5 = (long *)malloc(40*sizeof(long));

    if(arr5 == NULL){printf("Failed to allocate memory.\n");}

   heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);


printf("the following malloc operation is for type short int. \n ");

short int *arr6 = (short int *)malloc(10*sizeof(short int));

    if(arr6 == NULL){printf("Failed to allocate memory.\n");}

   heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);


printf("the following malloc operation is for type long int. \n ");


long int *arr7 = (long int *)malloc(25*sizeof(long int));

    if(arr7 == NULL){printf("Failed to allocate memory.\n");}

heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);


printf("the following malloc operation is for type long double. \n ");

long double *arr8 = (long double *)malloc(10*sizeof(long double));

    if(arr8 == NULL){printf("Failed to allocate memory.\n");}

   heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);



printf("the following malloc  operation is for type long long int. \n ");

long long int *arr9 = (long long int *)malloc(25*sizeof(long long int));

    if(arr9 == NULL){printf("Failed to allocate memory.\n");}

    heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);


printf("the following malloc  operation is for type double. \n ");

double *arr10 = (double *)malloc(10*sizeof(double));

    if(arr10 == NULL){printf("Failed to allocate memory.\n");}

    heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);


// end of malloc calls


printf("the following calloc operation is for type float. \n");

 float *arr11 = (float *)calloc(15, sizeof(float));

     if(arr11 == NULL){printf("Failed to allocate memory.\n");}// in case of allocation failed.


   heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);


printf("the following calloc operation is for type int. \n");

int *arr12 = (int *)calloc(10, sizeof(int));

    if(arr12 == NULL){printf("Failed to allocate memory.\n");}

   heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);



printf("the following operation calloc is for type char. \n");

char *arr13 = (char *)calloc(25, sizeof(char));

    if(arr13 == NULL){printf("Failed to allocate memory.\n");}

   heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);



printf("the following calloc operation is for type double. \n ");

double *arr14 = (double *)calloc(10, sizeof(double));

    if(arr14 == NULL){printf("Failed to allocate memory.\n");}

  heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);


printf("the following calloc operation is for type long. \n ");

long *arr15 = (long *)calloc(40, sizeof(long));

    if(arr15 == NULL){printf("Failed to allocate memory.\n");}

    heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);


printf("the following calloc operation is for type short int. \n ");

short int *arr16 = (short int *)calloc(10, sizeof(short int));

    if(arr16 == NULL){printf("Failed to allocate memory.\n");}

   heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);


printf("the following calloc operation is for type long int. \n ");


long int *arr17 = (long int *)calloc(25, sizeof(long int));

    if(arr17 == NULL){printf("Failed to allocate memory.\n");}

   heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);


printf("the following calloc operation is for type long double. \n ");

long double *arr18 = (long double *)calloc(10, sizeof(long double));

    if(arr18 == NULL){printf("Failed to allocate memory.\n");}

   heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);


printf("the following calloc operation is for type long long int. \n ");

long long int *arr19 = (long long int *)calloc(25,sizeof(long long int));

    if(arr19 == NULL){printf("Failed to allocate memory.\n");}

    heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);


printf("the following calloc operation is for type double. \n ");

double *arr20 = (double *)calloc(10, sizeof(double));

    if(arr20 == NULL){printf("Failed to allocate memory.\n");}

    heap_top = sbrk(0); // this is the address for top of heap

printf("Address for head of heap %p \n", heap_top);

printf("Address for bottom of heap %p \n", heap_bottom);

// end of calloc calls

memory_count = (unsigned) (heap_top-heap_bottom);

printf("Total memory ever allocated: %x \n", memory_count);

memory_count = 0x0;


printf("the following realloc operation is for arr1. \n");

free(arr2);

 arr1 = (float *)realloc(arr1,(10*sizeof(float)+1)); //reallocation which actually merge the space allocated earlier by arr1 and arr2

     if(arr1 == NULL){printf("Failed to reallocate memory.\n");}// in case of allocation failed.


   heap_top = (void *)arr1 + 10*sizeof(float)+1; // this is the address for top of reallocated memory

printf("Address for head of reallocated memory in heap %p \n", heap_top);

printf("Address of pointer %p \n", arr1);

memory_count = memory_count + (unsigned) (heap_top-(void *)arr1);

printf("memory reallocated: %x \n", (unsigned) (heap_top-(void *)arr1));





printf("the following realloc operation is for arr3. \n");

free(arr4);

arr3 = (char *)realloc(arr3,(10*sizeof(char)+1));

    if(arr3 == NULL){printf("Failed to reallocate memory.\n");}

      heap_top =(void *) arr3 + 10*sizeof(char)+1; // this is the address for top of reallocated memory

printf("Address for head of reallocated memory in heap %p \n", heap_top);

printf("Address of pointer %p \n", arr3);

memory_count = memory_count + (unsigned) (heap_top-(void *)arr3);

printf("memory reallocated: %x \n", (unsigned) (heap_top-(void *)arr3));




printf("the following realloc operation is for arr5. \n ");

free(arr6);

arr5 = (long *)realloc(arr5,(10*sizeof(long)+1));

    if(arr5 == NULL){printf("Failed to reallocate memory.\n");}

   heap_top = (void *)arr5 + 10*sizeof(long)+1; // this is the address for top of reallocated memory

printf("Address for head of reallocated memory in heap %p \n", heap_top);

printf("Address of pointer %p \n", arr5);

memory_count = memory_count + (unsigned) (heap_top-(void *)arr5);

printf("memory reallocated: %x \n", (unsigned) (heap_top-(void *)arr5));




printf("the following realloc operation is for arr7. \n ");

free(arr8);

arr7 = (long int *)realloc(arr7,(10*sizeof(long int)+1));

    if(arr7 == NULL){printf("Failed to reallocate memory.\n");}

     heap_top = (void *)arr7 + 10*sizeof(long int)+1; // this is the address for top of reallocated memory

printf("Address for head of reallocated memory in heap %p \n", heap_top);

printf("Address of pointer %p \n", arr7);

memory_count = memory_count + (unsigned) (heap_top-(void *)arr7);

printf("memory reallocated: %x \n", (unsigned) (heap_top-(void *)arr7));





printf("the following realloc operation is for arr9. \n ");

free(arr10);

arr9 = (long long int *)realloc(arr9,(10*sizeof(long long int)+1));

    if(arr9 == NULL){printf("Failed to reallocate memory.\n");}

   heap_top = (void *)arr9 + 10*sizeof(long long int)+1; // this is the address for top of reallocated memory

printf("Address for head of reallocated memory in heap %p \n", heap_top);

printf("Address of pointer %p \n", arr9);

memory_count = memory_count + (unsigned) (heap_top-(void *)arr9);

printf("memory reallocated: %x \n", (unsigned) (heap_top-(void *)arr9));





printf("the following realloc operation is for arr11. \n");

free(arr12);

 arr11 = (float *)realloc(arr11,(10*sizeof(float)+1)); //reallocation which actually merge the space allocated earlier by arr1 and arr2

     if(arr11 == NULL){printf("Failed to reallocate memory.\n");}// in case of allocation failed.


   heap_top = (void *)arr11 + 10*sizeof(float)+1; // this is the address for top of reallocated memory

printf("Address for head of reallocated memory in heap %p \n", heap_top);

printf("Address of pointer %p \n", arr11);

memory_count = memory_count + (unsigned) (heap_top-(void *)arr11);

printf("memory reallocated: %x \n", (unsigned) (heap_top-(void *)arr11));





printf("the following realloc operation is for arr13. \n");

free(arr14);

arr13 = (char *)realloc(arr13,(10*sizeof(char)+1));

    if(arr13 == NULL){printf("Failed to reallocate memory.\n");}

      heap_top = (void *)arr13 + 10*sizeof(char)+1; // this is the address for top of reallocated memory

printf("Address for head of reallocated memory in heap %p \n", heap_top);

printf("Address of pointer %p \n", arr13);

memory_count = memory_count + (unsigned) (heap_top-(void *)arr13);

printf("memory reallocated: %x \n", (unsigned) (heap_top-(void *)arr13));




printf("the following realloc operation is for arr15. \n ");

free(arr16);

arr15 = (long *)realloc(arr15,(10*sizeof(long)+1));

    if(arr15 == NULL){printf("Failed to reallocate memory.\n");}

   heap_top = (void *)arr15 + 10*sizeof(long)+1; // this is the address for top of reallocated memory

printf("Address for head of reallocated memory in heap %p \n", heap_top);

printf("Address of pointer %p \n", arr15);

memory_count = memory_count + (unsigned) (heap_top-(void *)arr15);

printf("memory reallocated: %x \n", (unsigned) (heap_top-(void *)arr15));




printf("the following realloc operation is for arr17. \n ");

free(arr18);

arr17 = (long int *)realloc(arr17,(10*sizeof(long int)+1));

    if(arr17 == NULL){printf("Failed to reallocate memory.\n");}

     heap_top = (void *)arr17 + 10*sizeof(long int)+1; // this is the address for top of reallocated memory

printf("Address for head of reallocated memory in heap %p \n", heap_top);

printf("Address of pointer %p \n", arr17);

memory_count = memory_count + (unsigned) (heap_top-(void *)arr17);

printf("memory reallocated: %x \n", (unsigned) (heap_top-(void *)arr17));





printf("the following realloc operation is for arr19. \n ");

free(arr20);

arr19 = (long long int *)realloc(arr19,(10*sizeof(long long int)+1));

    if(arr19 == NULL){printf("Failed to reallocate memory.\n");}

   heap_top = (void *)arr19 + 10*sizeof(long long int)+1; // this is the address for top of reallocated memory

printf("Address for head of reallocated memory in heap %p \n", heap_top);

printf("Address of pointer %p \n", arr19);

memory_count = memory_count + (unsigned) (heap_top-(void *)arr19);

printf("memory reallocated: %x \n", (unsigned) (heap_top-(void *)arr19));
// end of realloc, and also end of 10 free operation

heap_top = sbrk(0); // this is the address for top of heap
printf("Total memory reallocated: %x \n", memory_count);
printf("Heap size from bottom: %p to top: %p is %x \n", heap_bottom, heap_top, (unsigned)(heap_top - heap_bottom));
memory_count = (unsigned)(heap_top - heap_bottom) - (unsigned)(memory_count);

printf("Memory leak: %x", memory_count);

return 0;
}


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

// this is a really simple version of malloc, does no book keeping, thus no free realloc,etc.
//void *malloc(size_t size)
//{
//void *p = sbrk(0);
//void *request = sbrk(size);
//if(request == (void*) -1{return NULL; }// sbrk failed.
//else{assert(p== request); return p;}//Not thread safe.
//}
//
//
//}





