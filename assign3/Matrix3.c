/*@author: Aplomb Huang
*
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>

#define min(a,b) (a<b?a:b)

//double start, stop, used, mf;
//double ftime(void);
//void multiply (double *a, double *b, double *c, int n);

//double ftime (void)
//{
 //   struct tms t;
//
  //  times ( &t );

    //return (t.tms_utime + t.tms_stime) / 100.0;
//}

void block_multiply (double *a, double *b, double *c, int n)
{
   int i, j, k, io,jo,ko, block; block = n/2;

   for (i=0; i<n; i++)
   {
     for (j=0; j<n; j++)

         *(c+i*n +j) = 0;
    }

for(io = 0; io< n; io+=block-1)
{
   for(jo = 0; jo <n; jo+= block-1){

     for(ko = 0; ko<n; ko += block-1){

      for (i= io; i< min((io + block - 1),n); i++)
     {
       for (j=jo; j< min((jo + block - 1),n); j++)
       {
         for (k=ko; k< min((ko + block - 1),n); k++)
           *(c +i*n +j)= *(c +i*n +j) + *(a +i*n +j) * (*(b +i*n +j));
        }
     }
  }
 }
}

}

int main(void) {



    int i,j,k,n; // double fillValue = 0;


    n = 4096;



    double *matrixA = (double *)malloc(n * n * sizeof(double));
    double *matrixB = (double *)malloc(n * n * sizeof(double));
    double *matrixC = (double *)malloc(n * n * sizeof(double));

    for(i = 0; i <n; i++)
        {for(j = 0;j<n;j++)
             {
                 *(matrixA +i*n +j) = 7;
             }
        }

  //  for(i = 0; i <n; i++)
     //   {for(j = 0;j<n;j++)
         //    {
      //           printf("  %.1f",*(matrixA +i*n +j));
         //    }
       // }

        printf("\n \n");

        for(i = 0; i <n; i++)
        {for(j = 0;j<n;j++)
             {
                 *(matrixB +i*n +j) = 8;
             }
        }

  //  for(i = 0; i <n; i++)
    //    {for(j = 0;j<n;j++)
      //       {
        //         printf("  %.1f",*(matrixB +i*n +j));
          //   }
        //}


      //  start = ftime();
      block_multiply (matrixA,matrixB,matrixC,n);
      //stop = ftime();
      //used = stop - start;
      //mf = (n*n*n *2.0) / used / 1000000.0;
      printf ("done");
      //printf ( "Elapsed time:   %10.2f \n", used);
      //printf ( "DP MFLOPS:       %10.2f \n", mf);

      // for(i = 0; i <n; i++)
        //{for(j = 0;j<n;j++)
          //   {
            //     printf("  %.1f",*(matrixC +i*n +j));
             //}
        //}

return 0;
}
