#ifndef CMSC257_A1SUPPORT_INCLUDED
#define CMSC257_A1SUPPORT_INCLUDED

////////////////////////////////////////////////////////////////////////////////
//
//  File          : cmsc257-s17-assign1-support.h
//  Description   : This is a set of general-purpose utility functions we use
//                  for the 257 assignment #1.
//
//  Author   : Aplomb TR Huang
//  Created  : Feb 23rd, 2017
//
//
// Functional Prototypes

void float_display_array(float arr[], int l);
	// This function prints out the array of floating point values

void integer_display_array(int arr[], int l);
	// This function prints out the array of integer values

int float_evens(float arr[], int l);
	// Return the number of even numbers in the array (float version)

int integer_evens(int arr[], int l);
	// Return the number of even numbers in the array (int version)

int countBits(int x);
	// Count the number of '1' bits in the binary representation

void most_values(int arr[], int temp[], int l);
	// Print out the values with the most occurences in array

unsigned short int reverseBits(char *str);
        // Reverse the binary bit string

char * binaryString(int x);
        // Print the binary equivalent of the number passed

char * reversString(char *str);
        // reverse the string passed
        
void swap(int* a, int* b);
void integerQuickSort(int arr[], int low, int high);
int partition (int arr[], int low, int high);
        // Sort the integer array using QuickSort algorithm




#endif // CMSC257_A1SUPPORT_INCLUDED
