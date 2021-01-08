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
    // Create the socket.
    int sockfd = socket(AF_INET, SOCK_STREAM , 0);
    if (sockfd == -1) {
        printf("Fail to create a socket.\n");
        return 0;
    }

    // Set socket INFO.
    struct sockaddr_in serverInfo, clientInfo;
    socklen_t cslen = sizeof(clientInfo);
    memset(&serverInfo, 0, sizeof(serverInfo));
    serverInfo.sin_family = AF_INET;
    serverInfo.sin_addr.s_addr = INADDR_ANY;
    serverInfo.sin_port = htons(8787);

    // Bind the socket(sockfd) as INFO setting.
    bind(sockfd, (struct sockaddr *)&serverInfo, sizeof(serverInfo));

    // Enable a server to accept connections.
    listen(sockfd, 5);

    // Accept connections from clients.
    int forClientSockfd = accept(sockfd, (struct sockaddr*)&clientInfo, &cslen);
    printf("[Client] : %s:%d\n", inet_ntoa(clientInfo.sin_addr), ntohs(clientInfo.sin_port));

    // Close the socket.
    close(sockfd);

    return 0;
}