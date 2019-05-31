/*@Author: Aplomb TR Huang
**@ V # : 00800816
**@Class: CMSC 257 Spring 17
**@Assignment 6-client
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>

//int client_operation(void);

int main(void)// client_operation(void)
{
  int socket_fd;
  uint32_t value;
  struct sockaddr_in caddr;
  char *ip = "127.0.0.1";

  caddr.sin_family = AF_INET;
  caddr.sin_port = htons(16453);
  if (inet_aton(ip, &caddr.sin_addr) == 0) {return( -1); }

  socket_fd = socket(PF_INET, SOCK_STREAM,0);
  if (socket_fd == -1)
  {printf("error on socket creation [%s]\n", strerror(errno)); return(-1);}

  if ( connect(socket_fd, (const struct sockaddr *)&caddr, sizeof(struct sockaddr))==-1)
  {printf("Error on socket connect [%s]\n", strerror(errno)); return(-1);}

  value = htonl(1);
  if (write( socket_fd, &value, sizeof(value)) != sizeof(value)){printf("Error writing network data [%s]\n", strerror(errno)); 
  return (-1);}

  printf("Sent a value of [%d]\n", ntohl(value));

  if (read(socket_fd, &value, sizeof(value))!= sizeof(value)){printf("Error reading network data [%s]\n", strerror(errno)); return(-1);}

value = ntohl(value);
printf("Received a value of [%d]\n", value);

close(socket_fd);// close the socket
return(0);
}

//int main (int argc, char *argv[])
//{
  
//  client_operation();
// return 0;
//}



