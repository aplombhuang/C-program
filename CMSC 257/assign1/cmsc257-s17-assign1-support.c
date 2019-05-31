#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
@author: Aplomb TR Huang
@V ID #: V00800816
@Class : CMSC 257 Spring 17
@Assign: Assignment 1
@Task:   Complete the function definitions, functions are defined in Table1.
@Worked together with Brendan de Wet.
 */



void float_display_array(float arr[], int l)
{ int i;
    for(i = 0; i<l; i++){printf(" %.2f " , arr[i]);}
    printf("\n\n");

}

void integer_display_array(int arr[], int l)
{int i;
    for(i = 0; i<l; i++){printf(" %d ", arr[i]);}
    printf("\n\n");

}


int countBits(int x)
{ int count = 0;
    while(x != 0)
        {
            if((x&1) == 1){count ++;}

             x = x >> 1;
        }

        return count;
}

char * binaryString(int x)
{
    int n = 0, i = 0, count = 31;

   char *str, *temp;

 str = (char *) malloc(33*sizeof(char)); //because its an int bit bin number*/
 str[33] = '\0';

 while ( count > -1 ){ str[count]= '0';   count --; }

 count = 31;

      while(x != 0)
            {
                n = x%2;
                if(n == 1){str[count] = '1';}

                x = (x-(x%2))/2;

                count--;
            }

   temp = str;

    return temp;
}

char * reversString(char *str)
{
    int i = 0, j = 31;
    char *head = str;
    char *tail = str;

    while(i < j){

    head[i] = head[i]^tail[j];
    tail[j] = head[i]^tail[j];
    head[i] = head[i]^tail[j];

    i++; j--;

    }

    return str;

}

 unsigned short int reverseBits(char *str)
{
    unsigned short int rev = 0;

    int i, j = 0;

   for(i = 31; i <0; i--){

        if(str[i]==1){rev = rev + 1*pow(2,j);}
         j++;
        }

        return rev;
}



void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void integerQuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        integerQuickSort(arr, low, pi - 1);
        integerQuickSort(arr, pi + 1, high);
    }
}




int float_evens(float arr[], int l)
{
    int i, count = 0;

    for (i = 0; i<l; i++)
        {
            if((((int )arr[i])%2)==0){count++;}
        }
        return count;
}

int integer_evens(int arr[], int l)
{
    int i, count = 0;
    for(i = 0; i <l; i++)
        {
            if(arr[i]%2 == 0){count ++;}
        }
    return count ;
}

void most_values(int arr[], int temp[], int l)
{ // this is where the array is stored for check
  int hold = 0, count = 0;
  int i , j = 0 , max = 0;
  for(i = 0; i <l; i++)
    {

        if(hold == arr[i]){count ++; hold = arr[i];}
        else if(hold != arr[i])
            {if (max >= count){count = 1; hold = arr[i];}
             else {max = count; count = 1; hold = arr[i];}
            }
    }

      count = 1;j = 0;
      if(count == max){for(i = 0; i< l; i++){temp[j] = arr[i]; j++;}}
      else{
       for(i = 0; i< l; i++)
       {
            if(arr[i]== arr[i+1])
              {count++;
              if(count == max){temp[j] = arr[i+1]; j++;}}
            else{count = 1;}
            }
    }

    temp[20] = max;
}

