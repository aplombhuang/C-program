/*@author: Aplomb
**client trial 2
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main ()
{
    int cSocket;
    char buffer[1024];
    struct sockaddr_in sAddr;
    socklen_t addr_size;

    cSocket = socket(PF_INET,SOCK_STREAM,0);

    sAddr.sin_family = AF_INET;

    sAddr.sin_port = htons(2021);

    sAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    memset(sAddr.sin_zero, '\0', sizeof(sAddr.sin_zero));

    addr_size = sizeof(sAddr);

    connect(cSocket, (struct sockaddr *)&sAddr, addr_size);
    //connect the socket to the server using address string

    recv(cSocket, buffer, 1024, 0);
    //read message from server

    printf("Data received: %s", buffer);


    return 0;

}
