#ifndef CMSC257_A2SUPPORT_INCLUDED
#define CMSC257_A2SUPPORT_INCLUDED

////////////////////////////////////////////////////////////////////////////////
//
//  File          : cmsc257-s17-assign2-support.h
//  Description   : This is a set of general-purpose utility functions we use
//                  for the 257 assignment #2.
//
//  Author   : Aplomb TR Huang
//  Created  : Mar 18th, 2017
//
//
// Functional Prototypes

void *malloc(size_t size);
     // This function is the memory allocation function, this function allocate the size of memory on the heap
void *calloc(size_t size);
     //This function not only allocate a block of memory, but also format the memory with all 0's
void *realloc(void *ptr, size_t size);
     // This function relocates the memory
void *free(void *ptr);
     // This function frees up memory from variable that is no longer in use



#endif // CMSC257_A2SUPPORT_INCLUDED
