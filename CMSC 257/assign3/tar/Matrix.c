/*
**@author: Aplomb Huang
**@V ID #: 00800816
**@Assignment 3
**@Citation:stackoverflow.com/questions/5248915/execution-time-of-c-progrm
*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include<time.h>
#include<semaphore.h>
#include<pthread.h>
#include<errno.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/shm.h>


#define min(a,b) (a<b?a:b)//because the min method would be used later on, so it is defined here, choose the smaller of a or b

double  used, mf;

volatile int *mem;//share memory pointer

sem_t *sem;// semaphores variables


// the following are function headers

void multiply (double **a, double **b, double **c, int n);

void trans_Multiply (double **a, double **b, double **c, int n);

void block_Multiply (double **a, double **b, double **c, int n, int size);

void threaded_Blk_Multiply(double **a, double **b, double *c, int n, int size);

void print1_Matrix(double **a, int n, int flag );

void print_Matrix(double *a, int n, int flag );

//double ftime(void); //the implementation doesn't seems to be working, so i used another method to count the run time.
//double ftime (void)
//{
//  struct tms t;
//    time ( &t );
//    return (t.tms_utime + t.tms_stime) / 100.0;
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
         
	   c[i][j]= c[i][j] +  a[i][k] * b[j][k]; 
 	 // since matrixB is transposed, it is necessary to do the calculation in the transposed manner, thus position of j and k acts like matrixA.
	  }
     }
  }

// Professor said set n to 2^k and block to 2^k-1,k-2, k-3, so there will be 3 block calculations:



void block_Multiply (double **a, double **b, double **c, int n, int size)// calculation code is from the sudo code given
{
   int i, j, k, io,jo,ko, block;
if(n<= size){block = 2;}
else{    block = n/size;}

   for (i=0; i<n; i++)
   {
     for (j=0; j<n; j++)

         c[i][j] = 0;
    }

for(io = 0; io< n; io+=block-1)//sudo code says io from 1 to n step b
{
   for(jo = 0; jo <n; jo+= block-1)
 {
     for(ko = 0; ko<n; ko += block-1)
   {
       for (i= io; i< min((io + block - 1),n); i++)
      {
           for (j=jo; j< min((jo + block - 1),n); j++)
           {
             for (k=ko; k< min((ko + block - 1),n); k++)
             {
               c[i][j]= c[i][j] + a[i][k] * b[k][j];
	      }
           }
        }
      }
    }
  }
}


void threaded_Blk_Multiply (double **a, double **b, double *c, int n, int size)
{
   int i, j, k, io,jo,ko, block; int ii, count = 0;  double sum = 0;
if(n<= size){block = 2;}
else{    block = n/size;}

   for (i=0; i<n; i++)
   {
     for (j=0; j<n; j++)

         *(c+i*n +j) = 0;
    }

for(io = 0; io< n; io+=block-1)
{
   for(jo = 0; jo <n; jo+= block-1)
 {
     for(ko = 0; ko<n; ko += block-1)
  {
	pid_t childpid = fork(); count ++;
     if(childpid <0)
    {perror("fork() error"); exit(-1);}
     else{ if(childpid == 0){

           for (i= io; i< min((io + block - 1),n); i++)
           {
            for (j=jo; j< min((jo + block - 1),n); j++)
            {
             for (k=ko; k< min((ko + block - 1),n); k++)
             {  sem_wait(sem);

              *(c+i*n +j) += a[i][k] * b[k][j];

              sem_post(sem);

	          }
             }
            }
          exit(0);}
         else{wait(NULL);}
       }
  }
 }
}

}

void print1_Matrix(double **a, int n, int flag ) // this prints the matrix out
{ int i,j;
  if(flag){ //if user enter 1 as flag, matrix would be printed, else the funciton will do nothing
  for(i = 0; i <n; i++)
        {for(j = 0;j<n;j++)
             {
                 printf("  %.1f ",a[i][j]);
		if (j == n-1){printf("\n\n");}// since the 2D matrix is stored as 1D array, a return signal is needed when printing out.
             }
        }
  }

}

void print_Matrix(double *a, int n, int flag ) // this prints the resulting matrix out
{ int i,j;
  if(flag){ //if user enter 1 as flag, matrix would be printed, else the funciton will do nothing
  for(i = 0; i <n; i++)
        {for(j = 0;j<n;j++)
             {
                 printf("  %.1f ",*(a +i*n +j));
		if (j == n-1){printf("\n\n");}// since the 2D matrix is stored as 1D array, a return signal is needed when printing out.
             }
        }
  }

}


int main(void) {

  int i,j,k,n, b, flag, loop;  double fillIn;// variables needed for the questions below.
  int shmfd;  key_t key; char *name = "Aplomb"; //variables needed for share memory
  double **matrixA, **matrixB, **matrix_TransB, **matrixC;

do{//this do while loop is for user to determine if they want to keep running the program. enter 0 would terminates it. content of loop will run at least once

 printf("\n Matrix will be auto filled with preset numbers, see comments in implementation. \n");
  printf("To check calculation correctness, enter n <= 8, b choose 2 or 4 \n");

  printf("Enter matrix size n, all matrix will be n by n: \n");
  scanf("%d", &n);

  printf("Enter block size b for block multiplication: \n");
  scanf("%d", &b);

  printf("\n Do you want to print out matrixes? Enter 0 for NO, enter 1 for YES. \n");
  scanf("%d", &flag);


   if(n <= 8 ){fillIn = 1;}//if matrix size is smaller than 8, matrix content will be autofilled with positive integers starting with 1;

   if(n > 8){fillIn = (double) ((n*n)/(-2));}//if matrix size is over 8, matrix content will be autofilled with symetric numbers;

  // the following creates matrix A, B, c and transposed B as 2D arrays, but the result shared matrix stored in 1D format
    
     matrixA= (double**)malloc(n*sizeof(double));
     matrixB= (double**)malloc(n*sizeof(double));
     matrix_TransB= (double**)malloc(n*sizeof(double));//this variable stores the transposed matrixB.
     matrixC= (double**)malloc(n*sizeof(double));// this variable stores result matrix.

     for (i=0; i<n; i++)
     {
       matrixA[i]= malloc(sizeof(double)*n);
       matrixB[i]= malloc(sizeof(double)*n);
       matrix_TransB[i]= malloc(sizeof(double)*n);
       matrixC[i]= malloc(sizeof(double)*n);
      }

     
    double *shrd_Matrix = (double *)malloc(n * n * sizeof(double));// this variable stores result of thread_Matrix multiplication.

//share memory code is also copied as is from professor's code.
    shmfd = shm_open (name, O_RDWR | O_CREAT, 0666 );
    if ( shmfd < 0 ) {
        fprintf(stderr,"Could not create shared_memory\n");
        exit(1);
    }
    ftruncate ( shmfd, n*n*sizeof(double) );

    mem = (int *)mmap ( NULL, n*n*sizeof(double), PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0 );

    if ( mem < 0 ) {
        fprintf(stderr,"Could not map shared memory\n");
        exit(1);
    }
    close ( shmfd );
    shm_unlink ( name );

    shrd_Matrix = (double *)mem;

    // the semaphore related code are copy as is from source provided by professor

    sem = sem_open ( name, O_CREAT, 0666, 1 );
    if ( sem == NULL ) {
        fprintf(stderr,"Could not create  semaphore\n");
        exit(1);
    }
    sem_unlink ( name );

printf("Matrix size: %d \n", n);
//auto filling matrix.
   for(i = 0; i <n; i++)
        {for(j = 0;j<n;j++)
             {
                 matrixA[i][j] = fillIn++;
             }
        }

if(flag){printf("Matrix A: \n");}//determine whether to print matrix
print1_Matrix(matrixA, n , flag);

        printf("\n\n");

        for(i = 0; i <n; i++)
        {for(j = 0;j<n;j++)
             {
                 matrixB[i][j] = -- fillIn;
             }
        }
if(flag){printf("Matrix B: \n");}
  print1_Matrix(matrixB, n , flag);

printf ("\n\n");

   
for (i=0; i<n; i++)
     {
        for (j=0; j<n; j++)
          matrix_TransB[j][i]=matrixB[i][j];// by switching the position of i and j, I transposed the matrix B
      }


   if(flag){printf("Transposed matrix B: \n");}
   print1_Matrix(matrix_TransB, n, flag);

printf ("\n\n");

printf("The following is standard multiplication.\n");
clock_t start = clock();// this is the method I used to retrieve run time. method is cited.
       // start = ftime();
      trans_Multiply (matrixA,matrixB,matrixC,n);
      //stop = ftime();
clock_t stop = clock();
      if(flag){printf("Matrix C: \n");}
      print1_Matrix(matrixC, n , flag);


      used =(double) (stop - start)/CLOCKS_PER_SEC;
      mf = ( n*n*n *2.0) / used / 1000000.0;

      printf ( "Elapsed time:   %10.5f \n", used);
      printf ( "DP MFLOPS:      %10.5f \n", mf);
      printf ("\n\n");


 printf("The following is transposed multiplication.\n");
      start = clock();// this is the method I used to retrieve run time. method is cited.
       // start = ftime();
      trans_Multiply (matrixA,matrix_TransB,matrixC,n);
      //stop = ftime();
      stop = clock();
      if(flag){printf("Matrix C: \n");}
      print1_Matrix(matrixC, n , flag);


     used =(double) (stop - start)/CLOCKS_PER_SEC;
      mf = (( n*n*n *2.0) / used) / 1000000.0;

      printf ( "Elapsed time:   %10.5f \n", used);
      printf ( "DP MFLOPS:      %10.5f \n", mf);
      printf ("\n\n");

printf("The following is block multiplication with block size of %d.\n", b);
     start = clock();// this is the method I used to retrieve run time. method is cited.
       // start = ftime();

      block_Multiply (matrixA,matrixB,matrixC,n,b);

      //stop = ftime();
      stop = clock();

      if(flag){printf("Matrix C: \n");} //determine whether to print matrix c or not
      print1_Matrix(matrixC,n , flag);


      used =(double) (stop - start)/CLOCKS_PER_SEC;
      mf = (( n*n*n *2.0) / used) / 1000000.0;

      printf ( "Elapsed time:   %10.5f \n", used);
      printf ( "DP MFLOPS:      %10.5f \n", mf);
      printf ("\n\n");


      printf("The following is threaded block multiplication with block size of %d.\n" , b);
     start = clock();// this is the method I used to retrieve run time. method is cited.
       // start = ftime();

      threaded_Blk_Multiply(matrixA, matrixB, shrd_Matrix,n,b);

      //stop = ftime();
      stop = clock();

      if(flag){printf("Thread multiply calculation resulting Matrix: \n");} //determine whether to print matrix c or not
      print_Matrix(shrd_Matrix, n , flag);

      used =(double) (stop - start)/CLOCKS_PER_SEC;
      mf = (( n*n*n *2.0) / used) / 1000000.0;

      printf ( "Elapsed time:   %10.5f \n", used);
      printf ( "DP MFLOPS:      %10.5f \n", mf);
      printf ("\n\n");


printf("If you have other number of n, please press 1, else press 0 to exit: \n");
scanf("%d", &loop);

}while(loop);

return 0;}
