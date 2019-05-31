////////////////////////////////////////////////////////////////////////////////
//
//  File           : cmsc257-s17-assign2.c
//  Description    : This is where the driver function (main) is implemented for second assignment of CMSC257.
//   Author        : Aplomb TR Huang
//   Last Modified : Mar 22th, 2017
//

// Include Files
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include <math.h>
#include <stdlib.h>

// Project Includes
#include <cmsc257-s17-assign2-support.h>

//
// Functions

////////////////////////////////////////////////////////////////////////////////
//
// Function     : main
// Description  : The main function for the CMSC257 assignment #2
//
// Inputs       : argc - the number of command line parameters
//                argv - the parameters
// Outputs      : 0 if successful test, -1 if failure




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

