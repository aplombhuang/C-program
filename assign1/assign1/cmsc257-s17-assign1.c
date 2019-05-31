////////////////////////////////////////////////////////////////////////////////
//
//  File           : cmsc257-s17-assign1.c
//  Description    : This is the main source code for for the first assignment
//                   of CMSC257.  See the related
//                   assignment page for details.
//
//   Author        : Aplomb TR Huang
//   Last Modified : Mar 2rd, 2017
//

// Include Files
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Project Includes
#include <cmsc257-s17-assign1-support.h>

//
// Functions

////////////////////////////////////////////////////////////////////////////////
//
// Function     : main
// Description  : The main function for the CMSC257 assignment #1
//
// Inputs       : argc - the number of command line parameters
//                argv - the parameters
// Outputs      : 0 if successful test, -1 if failure

int main(int argc, char *argv[]) {

	// Local variables
	// NOTE: this is where you will want to add some new variables
	float f_array[20];
    int i, m_array[25], sortM_array[25]; // sortM_array is the variable that stores the int array after sorted.
    int count; // this variable would be used in all kinds of loops
    // unsigned short sh_array[25], rvs_array[25]; // reverse array variable
    
    if(0==1){count = *argv[1];} // taking in user input for count
    else {count = 20;}// default number

	// Step #1 - read in the float numbers to process
	for (i=0; i<count; i++) {
		scanf("%f", &f_array[i]);
	}
        printf("You have entered the following float values: ");
        float_display_array(f_array, count);

    // Step #2 - convert the floating point values to integers
      printf("The float values above are converted to int: \n");
       for(i = 0; i < count; i++)
       {
          m_array[i] = (int)f_array[i];
          printf("%d ", m_array[i]);
       }
        printf(" \n");
        // this is the end of casting float to int
       
	printf("The above values converted to absolute values: ");
       for (i = 0; i < count; i++)
	{
	  if(m_array[i] < 0) {m_array[i] = (m_array[i} ^ -1) +1;} // changing sign using bit-wise operation XOR;
          printf("%d ", m_array[i]);
	}
        printf(" \n"); 
	// this is the end of absolute value conversion
	
	printf("The above values converted to numbers between 0-15: ");
	for (i =0 ; i < count; i++)
	{m_array[i] = m_array[i] & (16 - 1); //bit-wise modulo operation
	 printf("%d ", m_array[i]);}
	 printf(" \n");
	// this is the end of mod 16 conversion

      

    // Step #3 - print out the integer and floating point arrays
        printf(" Printing out the integer and floating point arrays\n");
	float_display_array(f_array, count);
	 printf(" \n");
	integer_display_array(m_array, count);
	printf(" \n");

    
    // Step #4 - print out the number of '1's in each integer
	 printf(" The number of 1s in each integer: \n");
	for (i = 0; i < count; i++)
	{ printf("%d", countBits(m_array[i]));}    

	printf(" \n"); 

    // Step #5 - Sort the integer array using QuickSort and print the sorted array
	printf("Displaying int array after quick sort: \n");   
	for (i = 0; i < count; i++)
	{sortM_array[i]= m_array[i];}
	integerQuickSort(sortM_array, count);
	integer_display_array(sortM_array, count);
	printf(" \n");

    // Step #6 - figure out number of evens in each array (float and sorted integer arrays)
	printf("Number of even float in array: %d \n", float_evens(f_array, coutn)); 
	printf("Number of even int in array: %d \n", integer_evens(m_array, coutn));  
	printf(" \n");

    // Step #7 - print the most frequent values from the sorted integer array
	printf(" The  most frequent values are:\n");    
	int *mstFrq = most_values(m_array, count, 16);
	for (i =0 ; i < count; i++)
	{if (mstFrq [i]>0){printf(" %d ", smtFrq[i]);}
	} 
	printf(" \n"); 

    // Step #8 - print the integers corresponding to the reverse bit string from integer array
    printf("Reverse bit string from array: ");
	

	// Return successfully
	return(0);
}
