#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc , char *argv[])
{
    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM , 0);
    if (sockfd == -1) {
        printf("Fail to create a socket.\n");
        return 0;
    }

    // Set socket INFO.
    struct sockaddr_in serverINFO;
    memset(&serverINFO, 0, sizeof(serverINFO));
    serverINFO.sin_family = AF_INET;
    serverINFO.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverINFO.sin_port = htons(8787);

    // Connect to the server.
    int err = connect(sockfd, (struct sockaddr *)&serverINFO, sizeof(serverINFO));
    if (err == -1) {
        printf("Connection error.\n");
        return 0;
    }
    printf("[Server] : %s:%d\n", inet_ntoa(serverINFO.sin_addr), ntohs(serverINFO.sin_port));

    // Close the socket.
    close(sockfd);

    return 0;
}