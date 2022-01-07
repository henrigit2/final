#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <sys/socket.h>
#include <string.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <unistd.h>
#include <memory>



using namespace std;

class Server {
    private:
        int socket_conn;
        int newsocket_conn;
        sockaddr_in address;

    public:
        void createServer();
        void listenServer();
        void readServer(char *buffer);
        void sendServer(char *buffer);
        void pingServer();
        void closeServer();
        //void Error(string erro);
};


void Server::createServer(){

    socket_conn = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(5000);

    if(socket_conn == -1){
        cout << "Socket Failed" << endl;
    }

    if(bind(socket_conn, (struct sockaddr*)&address, sizeof(address)) == -1){
        cout << "Bind Failed" << endl;
    }
}

void Server::listenServer(){
    if(listen(socket_conn, 1) == -1){
        cout << "Listen Failed" << endl;
    }

    int address_len = sizeof(address);

    newsocket_conn = accept(socket_conn, (struct sockaddr*)&address, (socklen_t*)&address_len);

    if(newsocket_conn == -1){
        cout << "Accept Failed" << endl;
    }
}

void Server::readServer(char *buffer){

    read(newsocket_conn, buffer, sizeof(buffer));

}

void Server::sendServer(char *buffer){

    send(newsocket_conn, buffer, sizeof(buffer), 0);

}

void Server::pingServer(){
    while(true){

        //unique_ptr<Server> server(new Server);
        char buffer[1024];
        this->readServer(buffer);

        cout << buffer << endl;

        char *buffer2 = "Hello client";

        this->sendServer(buffer2);
        
    }
}

void Server::closeServer(){
    close(socket_conn);
}


#endif