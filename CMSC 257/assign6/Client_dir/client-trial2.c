/*@author: Aplomb
**client trial 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>

int rcv_file(int client_socket, char * fileName);

int main (int argc, char *argv[])
{
    int client_socket;
    char *file_name = "";
    char buffer[1024];
    struct sockaddr_in sAddr;
    socklen_t addr_size;

    client_socket = socket(PF_INET,SOCK_STREAM,0);

    sAddr.sin_family = AF_INET;

    sAddr.sin_port = htons(2021);

    sAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    memset(sAddr.sin_zero, '\0', sizeof(sAddr.sin_zero));

    addr_size = sizeof(sAddr);

    if (argc <2)
    { printf("enter the name of the file you want from the server:");
      scanf("%s", file_name);
    }
    else {file_name = argv[1];}

    if (connect(client_socket, (struct sockaddr *)&sAddr, addr_size)<0)    //connect the socket to the server using address string
    {perror("Can't connect to server"); exit(-1);}

    printf("connected. now transfer");

    rcv_file(client_socket, file_name);
    //receive file  from server

    printf("Data received: %s", buffer);

    if (close(client_socket) < 0)
    {perror("socket close error"); exit(-1);}

    return 0;

}

int rcv_file(int client_socket, char *file_name)
{
  char send_str[1024];//string send to server
  int f;//file handle for receiving file
  ssize_t sent_bytes, rcv_bytes, rcv_file_size;
  int rcv_count; //count receive calls
  char rcv_str[1024];// buffer receive from server
  size_t send_strlen;//length of str 

  sprintf(send_str,"%s \n", file_name);
  send_strlen = strlen(send_str);

  if ((sent_bytes = send(client_socket, file_name, send_strlen, 0))<0){perror("send error"); return -1;}

   if( (f = open(file_name, O_WRONLY|O_CREAT, 0666)) < 0)
   {perror("error creating file"); return -1;} 
   // attempt to create file, and it's rewritable.

   rcv_count = 0;// number of rcv calls 
   rcv_file_size = 0; // size of receive file

  while( (rcv_bytes = recv(client_socket, rcv_str, 1024, 0))>0) {
   rcv_count ++;
   rcv_file_size += rcv_bytes;

   if (write (f, rcv_str, rcv_bytes) <0)
   {perror("error writing to file"); return -1;}

  }
  close(f); //closing file

  printf("file transfer complete");

  return rcv_file_size;
}
