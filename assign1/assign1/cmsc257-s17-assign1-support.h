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

int float_display_array(float numf[], int i);
	// This function prints out the array of floating point values

int integer_display_array(int numb[], int i);
	// This function prints out the array of integer values

int float_evens(float numf[],int i);
	// Return the number of even numbers in the array (float version)

int integer_evens(int numb [], int i);
	// Return the number of even numbers in the array (int version)

int countBits(int count);
	// Count the number of '1' bits in the binary representation

int most_values(int numb [], int i, int occur);
	// Print out the values with the most occurences in array

unsigned short reverseBits(int reverse);
        // Reverse the binary bit string

void binaryString(int biStr);
        // Print the binary equivalent of the number passed

void integerQuickSort(int numb [], int i);
        // Sort the integer array using QuickSort algorithm
        

#endif // CMSC257_A1SUPPORT_INCLUDED
