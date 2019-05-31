/*@author: Aplomb Huang
*
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>
#include<time.h>

double  used, mf;//start, stop,
//double ftime(void);
void multiply (double *a, double *b, double *c, int n);

void print_Matrix(double *a, int n );

//double ftime (void)
//{
  //  struct tms t;

    //time ( &t );

    //return (t.tms_utime + t.tms_stime) / 100.0;
//}



void multiply (double *a, double *b, double *c, int n)
{
   int i, j, k; double sum = 0;

   for (i=0; i<n; i++)
   {
     for (j=0; j<n; j++)

         *(c+i*n +j) = 0;
    }

    for (i=0; i<n; i++)
    {
       for (j=0; j<n; j++)
       {
         for (k=0; k<n; k++)
           { sum = sum + *(a +i*n +k) * (*(b +k*n +j));}
        
	*(c +i*n +j)=sum; sum = 0;

	}
     }
  }

void print_Matrix(double *a, int n )
{ int i,j;
   for(i = 0; i <n; i++)
        {for(j = 0;j<n;j++)
             {
                 printf("  %.1f ",*(a +i*n +j));
		if (j == n-1){printf("\n\n");}
             }
        }
}


int main(void) {



   int i,j,k,n = 10; double fillIn = 0;





    double *matrixA = (double *)malloc(n * n * sizeof(double));
    double *matrixB = (double *)malloc(n * n * sizeof(double));
    double *matrixC = (double *)malloc(n * n * sizeof(double));

    for(i = 0; i <n; i++)
        {for(j = 0;j<n;j++)
             {
                 *(matrixA +i*n +j) = ++fillIn;
             }
        }

   print_Matrix(matrixA, n);

        printf("\n \n");

        for(i = 0; i <n; i++)
        {for(j = 0;j<n;j++)
             {
                 *(matrixB +i*n +j) = fillIn--;
             }
        }

  print_Matrix(matrixB, n);

printf ("\n\n");

clock_t tic = clock();

       //start = ftime();
      multiply (matrixA,matrixB,matrixC,n);
      //stop = ftime();
clock_t toc = clock();
      used = (double)(toc - tic)/CLOCKS_PER_SEC;

      print_Matrix(matrixC, n);
      //used = stop - start;
      mf = (n*n*n *2.0) / used / 1000000.0;
      printf ("\n\n");
      printf ( "Elapsed time:   %10.2f \n", used);
      printf ( "DP MFLOPS:       %10.2f \n", mf);

     //for(i = 0; i <n; i++)
       // {for(j = 0;j<n;j++)
         //    {
         //        printf("  %.1f",*(matrixC +i*n +j));
         //    }
        //}

return 0;}
