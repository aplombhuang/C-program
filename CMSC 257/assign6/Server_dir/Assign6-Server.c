/*@author: Aplomb TR Huang
**@ V # : 00800816
**@Class: CMSC 257 Spring 17
**@Assignment6-Server
**@Citation:
www.programminglogic.com/example-of-client-server-program-in-c-using-sockets-and-tcp/
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>

//int server_operation(void);

int main (void)// server_operation(void)
{
 int server, client;
 uint32_t value, inet_len;
 struct sockaddr_in saddr, caddr;

 saddr.sin_family = AF_INET;
 saddr.sin_port = htons(16453);
 
 saddr.sin_addr.s_addr = htonl(INADDR_ANY);//or equal inet_addr("127.0.0.1");
 server = socket(PF_INET, SOCK_STREAM, 0);  
 
 if ( server == -1)
 { printf("Error on socket creation [%s]\n", strerror(errno)); return -1; }
 
 if (bind(server, (struct sockaddr *)&saddr, sizeof(struct
 sockaddr))==-1){printf("Error on socket bind[%s]\n",strerror(errno)); return(-1);}

 if (listen (server, 5) == -1)
 {printf("Error on socket listen [%s]\n", strerror(errno));  return(-1);}

 while(1){
 
  inet_len = size0f(caddr);
  
  if ((client = accept(server, (struct sockaddr *)&caddr, &inet_len)) == -1)
  {printf("Error on client accept [%s]\n", strerror(errno)); close(server);
  return (-1);
  }
  printf("Server new client connection [%s/%d]", inet_ntoa(caddr.sin_addr), caddr.sin_port);

 if(read( client, &value, sizeof(value))!= sizeof(value))
 {printf("Error writing network data [%s]\n", strerror(errno)); close(server); return (-1);
 }
 
 value = ntohl(value);
 printf("Received a value of [%d]\n", value);
 value ++;

 if(write (client, &value, size(value))!= sizeof(value))
 {printf("Error writing network data [%s]\n", strerror(errno)); close(server); return(-1);
 }
 printf("Sent a value of [%d]\n", value);
 close(client);//Close the socket
 }
 return (0);
}

//int main (int argc, char *argv[])
//{
// char buffer[1024];// buffer size
// socklen_t addr_size;
// struct sockaddr_storage serverStorage;
 
// memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);



// server_operation();
 
// return 0;
//}



