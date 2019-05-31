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
#include <fcntl.h>
#include <unistd.h>


void get_file_name(int client, char *file_name);
int send_file(int client, char *file_name);
//function headers

int main(int argc, char *argv[])
{
  int server, client;
  uint32_t value, inet_len;
  char *file_name = "";
  char buffer[1024];// buffer size
  struct sockaddr_in sAddr, cAddr; // server and client address
  struct sockaddr_storage s_Storage;
  socklen_t addr_size;

  server = socket(PF_INET, SOCK_STREAM, 0); // SOCKET created

 sAddr.sin_family = AF_INET; // address family = internet

  sAddr.sin_port= htons(2021); // set port number

  sAddr.sin_addr.s_addr = inet_addr("127.0.0.1");// set server ip addressto local host

  memset(sAddr.sin_zero, '\0', sizeof( sAddr.sin_zero));
  memset(cAddr.sin_zero, '\0', sizeof(cAddr.sin_zero));
  //set all bits of the padding field to 0

 if(server == -1)
 {printf("Error on socket creation [%s]\n", strerror(errno)); return -1;}

 if ( bind(server,(struct sockaddr *)&sAddr, sizeof(sAddr))== -1){printf("Error on socket bind[%s]\n", strerror(errno)); return (-1);}
 //binding address struct to socket

 if(listen(server,5)==0){printf("Listening \n");}
 else {printf("Error on socket listen [%s] \n", strerror(errno));return (-1);} //listen on the socket, with 5 max connection request

for( ; ;)
{
 addr_size = sizeof(cAddr) ;

 if ( (client = accept(server, (struct sockaddr *)&cAddr, &addr_size)) <0)
 {perror("accept error"); break;}
 // accept call creates new socket for incoming connection

 get_file_name(client, file_name);
 
  send_file(client, file_name);

 close(client);

//strcpy(buffer, "Hello Server \n");
//send(client,buffer,13,0);
//send message to socket of the incoming connection
}
 close(server); 

return 0;}

void get_file_name(int client, char *file_name)
{
 char rcv_str[1024];// to store received string
 ssize_t rcv_bytes; // bytes received from client

 if ((rcv_bytes = recv(client, rcv_str, 1024, 0))< 0)
 {perror("error receiving "); return;}

 sscanf(rcv_str, "%s\n", file_name);
}

int send_file(int client, char *file_name)
{
 int sent_count;
 ssize_t read_bytes, sent_bytes, sent_file_size;

 char buffer[1024];
 char *errmsg_notfound = "File not found\n";

 int f;//file handle

 sent_count = 0;
 sent_file_size = 0;

 if((f= open(file_name, O_RDONLY))<0)
 { perror(file_name);
   if ( (sent_bytes = send(client, errmsg_notfound,
   strlen(errmsg_notfound),0))<0) {perror("send error"); return -1;}
 }
 else
 {
  printf("sending file");
  while((read_bytes = read(f, buffer, 1024))>0)
  {
   if ((sent_bytes = send(client,buffer, read_bytes, 0))<0)
   {    perror("send error"); return -1;   }
 
  sent_count ++; sent_file_size += sent_bytes;
 }
  close(f);
 }
 printf("Done");
 return sent_count;
}



