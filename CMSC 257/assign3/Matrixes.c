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
void multiply (double **a, double **b, double **c, int n);

void trans_Multiply (double **a, double **b, double **c, int n);

void print_Matrix(double a[n][n], int n );


//double ftime (void)
//{
  //  struct tms t;

    //times ( &t );

    //return (t.tms_utime + t.tms_stime) / 100.0;
//}


void multiply (double **a, double **b, double **c, int n)
{
   int i, j, k;

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
           c[i][j]= c[i][j] + a[i][k] * b[k][j];
        }
     }
  }


void trans_Multiply (double **a, double **b, double **c, int n)
{
   int i, j, k;

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
           c[i][j]= c[i][j] + a[i][k] * b[j][k];
        }
     }
  }

void print_Matrix(double **a, int n )
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
    double fillIn = 0;


    printf("Enter matrix size n, all matrix will be n by n: \n");
  scanf("%d", &n);

  int i, j, n;
   double **matrixA, **matrixB, **matrix_TransB, **matrixC;

    printf ( "Enter the value of n: ");
    scanf ( "%d", &n);

   //Populate arrays....
     matrixA= (double**)malloc(n*sizeof(double));
     matrixB= (double**)malloc(n*sizeof(double));
     matrix_TransB= (double**)malloc(n*sizeof(double));
     matrixC= (double**)malloc(n*sizeof(double));

     for (i=0; i<n; i++)
     {
       matrixA[i]= malloc(sizeof(double)*n);
       matrixB[i]= malloc(sizeof(double)*n);
       matrix_TransB[i]= malloc(sizeof(double)*n);
       matrixC[i]= malloc(sizeof(double)*n);
      }

     for (i=0; i<n; i++)
     {
        for (j=0; j<n; j++)
         a[i][j]=++fillIn;
      }

     for (i=0; i<n; i++)
     {
        for (j=0; j<n; j++)
          b[i][j]=fillIn--;
      }
 printf ("\n\n");

clock_t tic = clock();

       //start = ftime();
      multiply (matrixA,matrixB,matrixC,n);
      //stop = ftime();
clock_t toc = clock();
      used = (double)(toc - tic)/CLOCKS_PER_SEC;

     // print_Matrix(matrixC, n);
      //used = stop - start;
      mf = (n*n*n *2.0) / used / 1000000.0;
      printf ("\n\n");
      printf ( "Elapsed time:   %10.2f \n", used);
      printf ( "DP MFLOPS:       %10.2f \n", mf);

printf ("\n\n");

 tic = clock();

       //start = ftime();
      trans_Multiply (matrixA,matrix_TransB,matrixC,n);
      //stop = ftime();
toc = clock();
      used = (double)(toc - tic)/CLOCKS_PER_SEC;

     // print_Matrix(matrixC, n);
      //used = stop - start;
      mf = (n*n*n *2.0) / used / 1000000.0;
      printf ("\n\n");
      printf ( "Elapsed time:   %10.2f \n", used);
      printf ( "DP MFLOPS:       %10.2f \n", mf);



return 0;}
