#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <sys/socket.h>
#include <string.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <unistd.h>
#include <memory>
#include "../entities/Icmp.h"



using namespace std;

class Client {
    private:
        int socket_conn;
        sockaddr_in address;

    public:
        void createClient();
        void connectClient();
        void readClient(char *buffer);
        void sendClient(char *buffer);
        void pingClient();
        void closeClient();
        //void Error(string erro);
};


void Client::createClient(){

    socket_conn = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(5000);

    if(socket_conn == -1){
        cout << "Socket Failed";
    }
}

void Client::connectClient(){
    if(connect(socket_conn, (struct sockaddr*)&address, sizeof(address)) < 0){
        cout << "Connect Failed" << endl;
    }
}

void Client::readClient(char *buffer){

    read(socket_conn, buffer, sizeof(buffer));

}

void Client::sendClient(char *buffer){

    send(socket_conn, buffer, sizeof(buffer), 0);

}

void Client::pingClient(){
    Icmp pkt;

    pkt.type = 8;

    char *d;

    encode(d, pkt);

    while(true){

        //unique_ptr<Client> client(new Client);
    
        usleep(1000000);

        char *buffer2 = "Hello server";

        this->sendClient(buffer2);

        char buffer[1024];
        this->readClient(buffer);

        cout << buffer << endl;

        
        
    }
}

void Client::closeClient(){
    close(socket_conn);
}


#endif