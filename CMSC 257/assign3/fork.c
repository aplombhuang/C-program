/*
*
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>
#include<semaphore.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>


int main(void)
{  int i,j,k,n = 4,count = 0;
 
                              for (i = 0; i<n;i++)
				{
	pid_t childpid = fork(); count ++;
     if(childpid <0)
     {perror("fork() error"); exit(-1);}
     else{ if(childpid == 0){
				 for(j = 0; j< n; j++)
				  {
				   for(k = 0; k<n; k++){ printf("%d %d %d %d \n",i, j, k,count);}
				  }
			       
           
  printf("%d \n", childpid); 
  exit(0);}
             else{wait(NULL);}
       } 
}
    for(i = 0;i < count; i++){}
  
return 0;
}
