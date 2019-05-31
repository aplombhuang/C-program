/*@This is the server
 *@author: Aplomb Huang
*
*/
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define SHMSZ 64 //defined share memory size is 64 byte

int main()
{
 char c; int shmid; key_t key; char *shm, *s;

 key = 4869;//i just name my share memory "4869"

 if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666 )) < 0)
 {perror("shmget"); exit(1);} //created the share memory sement

if((shm = shmat(shmid, NULL, 0))== (char *)-1)
{perror("shmat"); exit(1);} // attach the segment to data space

 s = shm;
 
 for (c = 'a'; c <= 'z'; c++){*s++ = c; } *s = NULL;

 while(*shm != '*'){sleep(1);}

//exit(0);

return 0;}


