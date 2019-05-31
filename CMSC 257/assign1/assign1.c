/*
 * @ author aplomb
 */
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


void float_display_array(float arr[], int l);
void integer_display_array(int arr[], int l);
int countBits(int x);
char * binaryString(int x);
unsigned short int reverseBits(char *str);
void swap(int* a, int* b);
void integerQuickSort(int arr[], int low, int high);
int partition (int arr[], int low, int high);
int float_evens(float arr[], int l);
int integer_evens(int arr[], int l);
void most_values(int arr[], int temp[], int l);
char * reversString(char *str);



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
    int j;
    for ( j = low; j <= high- 1; j++)
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
