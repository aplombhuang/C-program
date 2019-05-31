/*@author: Aplomb Huang
*
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>
#include<time.h>

double used, mf; //start, stop,
//double ftime(void);
void multiply (double *a, double *b, double *c, int n);

void print_Matrix(double *a, int n );

//double ftime (void)
//{
  //  struct tms t;

    //times ( &t );

    //return (t.tms_utime + t.tms_stime) / 100.0;
//}


void trans_Multiply (double *a, double *b, double *c, int n)
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
           { sum = sum + *(a +i*n +k) * (*(b +j*n +k));}// since matrixB is transposed, it is necessary to do the calculation in the transposed manner, thus position of j and k acts like matrixA.
        
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
    double *matrixTrans_B = (double *)malloc(n * n * sizeof(double));//this variable stores the transposed matrixB.
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
                 *(matrixB +i*n +j) = fillIn--  ;
             }
        }

   print_Matrix(matrixB, n);

printf ("\n\n");

      for(i = 0; i <n; i++)
        {for(j = 0;j<n;j++)
             {
                 *(matrixTrans_B +j*n +i) = *(matrixB +i*n +j)  ;// by switching the position of i and j, I transposed the matrix B
             }
        }
   printf("Transposed matrix B: \n");
   print_Matrix(matrixTrans_B, n);

printf ("\n\n");

clock_t start = clock();
       // start = ftime();
      trans_Multiply (matrixA,matrixTrans_B,matrixC,n);
      //stop = ftime();
clock_t stop = clock();
      print_Matrix(matrixC, n);
      used =(double) (stop - start)/CLOCKS_PER_SEC;
      mf = (n*n*n *2.0) / used / 1000000.0;
      printf ("\n\n");

	
      printf ( "Elapsed time:   %10.2f \n", used);
      printf ( "DP MFLOPS:       %10.2f \n", mf);

   

return 0;}
