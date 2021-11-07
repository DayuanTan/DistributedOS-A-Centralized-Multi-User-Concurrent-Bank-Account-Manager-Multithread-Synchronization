#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
using namespace std;

#define PORT 8080

   
int main(int argc, char const *argv[])
{
    int client_socket_fd, valread;
    char client_read_buffer[1024] = {0};

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    // server_addr.sin_addr.s_addr = inet_addr(argv[1]); // hardcode to 127.0.0.1
    server_addr.sin_port = htons(PORT);  
    
    
    

    // Creating socket file descriptor (IPv4, TCP, IP)
    if ((client_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Client: Socket creation error \n");
        return -1;
    }

       
    // Converting IPv4 and IPv6 addresses from text to binary form,
    //   from character string src into a network
    //   address structure in the af address family, then copies the
    //   network address structure to dst.
    if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr)<=0) 
    {
        printf("\nClient: Invalid address/ Address not supported \n");
        return -1;
    }
   
    // Connecting server, return 0 with success, return -1 with error
    if (connect(client_socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("\nClient: Connection Failed \n");
        return -1;
    }

    char server_ip[INET_ADDRSTRLEN]="";
    inet_ntop(AF_INET, &server_addr.sin_addr, server_ip, INET_ADDRSTRLEN);
    printf("Client: connected server(%s:%d). \n", server_ip, ntohs(server_addr.sin_port));


    // sending a message to server
    const char *hello = "Hello from client";
    send(client_socket_fd , hello , strlen(hello) , 0 );
    printf("Client: sent message: '%s'\n", hello);
    valread = read( client_socket_fd , client_read_buffer, 1024);
    printf("Client: read: '%s'\n",client_read_buffer );

    int input;
    while (1){
        cout << "Do you want to terminate this client? \n(Input 1 for yes, 0 for no.)" << endl;
        cin >> input;
        if (input == 1) {
            close(client_socket_fd);
            return 0;
        }
    }
}