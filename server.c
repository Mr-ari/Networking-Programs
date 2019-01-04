#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<netinet/in.h>

void error(char *str){
    perror(str); 
    exit(1);
}

int main(int argc, char const *argv[])
{   
    if(argc<2){
    printf("Please Provide the Port Number \n");
    exit(0);
    } 

    int portNo,socketFD;
    char buffer[1000];
    struct sockaddr_in server_addr;

    memset(buffer,'0',sizeof(buffer));
    memset(& server_addr,'0',sizeof(server_addr));
    
    portNo = atoi(argv[2]);

    //creating socket
    socketFD = socket(AF_INET,SOCK_STREAM,0);
    printf("Socket is succesfully created ! \n");

    server_addr.sin_addr.s_addr = AF_INET;
    server_addr.sin_port = htonl(portNo);
    server_addr.sin_family = INADDR_ANY;

    //binding 

    bind(socketFD,(struct sockaddr *) &server_addr,sizeof(server_addr));

    if(listen(socketFD,5) == -1) {printf("Failed to listen\n");return 1;}


    return 0;
}
