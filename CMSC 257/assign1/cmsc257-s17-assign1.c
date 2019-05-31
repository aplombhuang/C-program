////////////////////////////////////////////////////////////////////////////////
//
//  File           : cmsc257-s17-assign1.c
//  Description    : This is the main source code for for the first assignment
//                   of CMSC257.  See the related
//                   assignment page for details.
//
//   Author        : Aplomb TR Huang
//   Last Modified : Mar 2rd, 2017
//@Worked together with Brendan de Wet.

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

int main (void)
{
   float f_arr[20]; int i_arr[20], m_arr[20], q_arr[20];
   //unsigned short sh_arr[20], rsh_arr[20];

   int i, max = 20;


   for(i = 0; i < max; i++)
    {scanf("%f" , &f_arr[i]);}

   printf("Entered float values : ");
   float_display_array(f_arr, max);

   printf("Convert float into int by ");
   for(i = 0; i < max; i++){m_arr[i] = (int)f_arr[i];}
   printf("casting int to result: ");

   for(i = 0; i < max; i++){i_arr[i] = m_arr[i];}

   integer_display_array(m_arr, max);

   for(i = 0; i < max; i++){if(m_arr[i]<0){m_arr[i] = (m_arr[i]*(-1));}}
   printf("Absolute values of integer array: \n");
   integer_display_array(m_arr, max);

   for(i = 0; i < max; i++){m_arr[i] = m_arr[i] & (16-1);}

   printf("Modulo 16 result : ");
   integer_display_array(m_arr, max);



   printf("Count bits results :");
   for(i = 0; i < max; i++){printf(" %d ", countBits(m_arr[i]));}
   printf("\n\n");


   printf("Quick Sort results : \n");

   for(i = 0; i < max; i++){q_arr[i] = i_arr[i];}

   integerQuickSort(q_arr,0 , max-1);
   integer_display_array(q_arr, max);

   printf("Number of even float result : %d \n" , float_evens(f_arr, max));
   printf("Number of even integer result : %d \n", integer_evens(i_arr, max));

   printf("integers that occurs the most: \n");
   int mstval[21] = {-1, -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};// this will later on stores max int result

   most_values(q_arr, mstval, max);

   for(i = 0; i < max; i++)
    {
        if (mstval[i]>=0){printf(" %d, ", mstval[i]);}
    }

    printf("occur frequency: %d", mstval[20]);
    printf("\n\n");


    printf("Integers corresponding to reverse bit result :\n");
    printf("Integer|           Bit Value           |              Reverse Bit           | Value Reversed Int \n");
    for(i = 0 ; i< max; i++)
        {
            char * result = binaryString(q_arr[i]);
            printf("%d",q_arr[i]);
            printf("    |%s", result );
            char *reve = reversString(result);
            printf("| %s", reve);
            printf("| %d", reverseBits(reve));

            printf("\n\n");

        }
   printf("the reverse bits are all 0 because the reversed string is the length of int, but reverse bit is short int.");

return 0;}
