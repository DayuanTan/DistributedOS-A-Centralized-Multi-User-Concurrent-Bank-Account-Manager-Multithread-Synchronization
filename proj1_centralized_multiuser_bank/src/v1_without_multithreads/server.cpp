#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080
 
int main(int argc, char *argv[])
{
    // /* deal with input arguments*/
    // std::cout << "print arguments:\nargc == " << argc << '\n';
    // for(int ndx{}; ndx != argc; ++ndx) {
    //     std::cout << "argv[" << ndx << "] == " << argv[ndx] << '\n';
    // }
    // std::cout << "argv[" << argc << "] == "
    //           << static_cast<void*>(argv[argc]) << '\n';
    
    

    // Socket Cite: https://www.geeksforgeeks.org/socket-programming-cc/?ref=lbp
    int server_socket_fd, new_socket, valread;
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;    // IPv4
    server_address.sin_addr.s_addr = INADDR_ANY; // localhost
    server_address.sin_port = htons( PORT ); // 8080
    int opt = 1; // for setsockopt

    // Creating socket file descriptor (IPv4, TCP, IP)
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Server: socket failed");
        exit(EXIT_FAILURE);
    }
       
    // Optional: it helps in reuse of address and port. Prevents error such as: “address already in use”.
    if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("Server: setsockopt");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (bind(server_socket_fd, (struct sockaddr *)&server_address, 
                                 sizeof(server_address))<0)
    {
        perror("Server: bind failed");
        exit(EXIT_FAILURE);
    }

    // Putting the server socket in a passive mode, waiting for the client to approach the server to make a connection
    // The backlog=7, defines the maximum length to which the queue of pending connections for sockfd may grow. 
    // If a connection request arrives when the queue is full, the client may receive an error with an indication of ECONNREFUSED.
    if (listen(server_socket_fd, 7) < 0)
    {
        perror("Server: listen");
        exit(EXIT_FAILURE);
    }
    printf("Server: server is listening ...\n");

    // Setting up buffer for receiving msg
    char recv_buf[65536];
    memset(recv_buf, '\0', sizeof(recv_buf));

    while (1) { // block on accept() until positive fd or error
        struct sockaddr_in client_addr;
        socklen_t length = sizeof(client_addr);
        // Extracting the first connection request on the queue of pending connections for the listening socket (server_socket_fd) 
        // Creates a new connected socket, and returns a new file descriptor referring to that socket
        if ((new_socket = accept(server_socket_fd, (struct sockaddr *)&client_addr, 
                        (socklen_t*)&length))<0)
        {
            perror("Server: accept");
            exit(EXIT_FAILURE);
        }
        
        // converting the network address structure src in the af address family into a character string.
        char client_ip[INET_ADDRSTRLEN] = "";
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
        printf("Server: new client accepted. client ip and port: %s:%d\n", client_ip, ntohs(client_addr.sin_port));

        while(recv(new_socket, recv_buf, sizeof(recv_buf), 0) > 0 ){
            printf("Server: recv from client(%s:%d): '%s' \n", client_ip, ntohs(client_addr.sin_port), recv_buf);
            memset(recv_buf, '\0', strlen(recv_buf));
            break;
        }

        // valread = read( new_socket , buffer, 1024);
        // printf("%s\n",buffer );

        // sending a message to client
        const char *msg = "Hello from server";
        send(new_socket , msg , strlen(msg) , 0 );
        printf("Server: sent to client(%s:%d): '%s'\n", client_ip, ntohs(client_addr.sin_port), msg);
    }

    printf("Server: server stopped. \n");
    close(server_socket_fd);
    return 0;
}
