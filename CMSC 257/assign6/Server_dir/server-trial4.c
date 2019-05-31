/*author Aplomb
**this is server trial 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
  int server, client;
  uint32_t value, inet_len;
  char buffer[1024];// buffer size
  struct sockaddr_in sAddr; // server address
  struct sockaddr_storage s_Storage;
  socklen_t addr_size;

  server = socket(PF_INET, SOCK_STREAM, 0); // SOCKET created

 sAddr.sin_family = AF_INET; // address family = internet

  sAddr.sin_port= htons(2021); // set port number

  sAddr.sin_addr.s_addr = inet_addr("127.0.0.1");// set server ip addressto local host

  memset(sAddr.sin_zero, '\0', sizeof sAddr.sin_zero);//set all bits of the padding field to 0

 if(server == -1)
 {printf("Error on socket creation [%s]\n", strerror(errno)); return -1;}

 if ( bind(server,(struct sockaddr *)&sAddr, sizeof(sAddr))== -1){printf("Error on socket bind[%s]\n", strerror(errno)); return (-1);}
 //binding address struct to socket

 if(listen(server,5)==0){printf("Listening \n");}
 else {printf("Error on socket listen [%s] \n", strerror(errno));return (-1);} //listen on the socket, with 5 max connection request

 addr_size = sizeof(s_Storage) ;
 client = accept(server, (struct sockaddr *)&s_Storage, &addr_size);
 // accept call creates new socket for incoming connection

strcpy(buffer, "Hello Server \n");
send(client,buffer,13,0);
//send message to socket of the incoming connection



return 0;}

