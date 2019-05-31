#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SRV_PORT 2021
//SERVER PORT
#define MX_RCV_BUF 1024
//maximum receive buffer 
#define MX_SND_BUF 1025
//maximium send buffer

int rcv_file(int, char *); //file receive function header

int main (int argc, char *argv[])
{
 int client_socket;
 struct sockaddr_in srv_addr; // struct server address
 client_socket = socket(PF_INET, SOCK_STREAM,0);
 srv_addr.sin_family = AF_INET;
 srv_addr.sin_port = htons(SRV_PORT);
 srv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

 memset(srv_addr.sin_zero,'\0', sizeof(srv_addr.sin_zero));
//zero-fill srv_addr structure



 if (argc < 2){printf("please enter the name of file you want to get.");}



 return 0;
}
