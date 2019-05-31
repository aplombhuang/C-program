/*@this is the client
 *@author: Aplomb Huang
 */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SHMSZ 64

int main()
{
 int shmid; key_t key; char * shm, *s;

 key = 4869;

 if ((shmid = shmget(key, SHMSZ, 0666))<0)
 {perror("shmget");exit(1);}

 if ((shm = shmat(shmid, NULL, 0))== (char *) -1)
 {perror(*s);exit(1);}

 for (s = shm; *s != NULL; s++){putchar(*s);} 
 putchar('\n');

 *shm = '*';

return 0;}
