/*@author: Aplomb Huang
*
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>
#include<time.h>

int n;
double  used, mf;//start, stop,
//double ftime(void);
void multiply (double a[n][n], double b[n][n], double c[n][n], int n);

void print_Matrix(double a[n][n], int n );


//double ftime (void)
//{
  //  struct tms t;

    //times ( &t );

    //return (t.tms_utime + t.tms_stime) / 100.0;
//}


void multiply (double a[n][n], double b[n][n], double c[n][n], int n)
{
   int i, j, k; double sum = 0;

   for (i=0; i<n; i++)
   {
     for (j=0; j<n; j++)

         c[i][j] = 0;
    }

    for (i=0; i<n; i++)
    {
       for (j=0; j<n; j++)
       {
         for (k=0; k<n; k++)
           { sum = sum + a[i][k] * b[j][k] ;}

	c[i][j]=sum; sum = 0;

	}
     }
  }

void print_Matrix(double a[n][n], int n )
{ int i,j;
   for(i = 0; i <n; i++)
        {for(j = 0;j<n;j++)
             {
                 printf("  %.1f ",a[i][j]);
		if (j == n-1){printf("\n\n");}
             }
        }
}

int main(void) {
int i,j,k;
   n= 128; double fillIn = 0;

  double matrixA[n][n] , matrixB[n][n] , matrix_TransB[n][n], matrixC[n][n];

    for(i = 0; i <n; i++)
        {for(j = 0;j<n;j++)
             {
                 matrixA[i][j] = ++fillIn;
             }
        }

   //print_Matrix(matrixA, n);

        printf("\n \n");

        for(i = 0; i <n; i++)
        {for(j = 0;j<n;j++)
             {
                 matrixB[i][j] = fillIn--;
             }
        }

//  print_Matrix(matrixB, n);

printf ("\n\n");


        for(i = 0; i <n; i++)
        {for(j = 0;j<n;j++)
             {
                 matrix_TransB[j][i] = matrixB[i][j] ;
             }
        }

 // print_Matrix(matrix_TransB, n);

printf ("\n\n");

clock_t tic = clock();

       //start = ftime();
      multiply (matrixA,matrix_TransB,matrixC,n);
      //stop = ftime();
clock_t toc = clock();
      used = (double)(toc - tic)/CLOCKS_PER_SEC;

     // print_Matrix(matrixC, n);
      //used = stop - start;
      mf = (n*n*n *2.0) / used / 1000000.0;
      printf ("\n\n");
      printf ( "Elapsed time:   %10.2f \n", used);
      printf ( "DP MFLOPS:       %10.2f \n", mf);



return 0;}
