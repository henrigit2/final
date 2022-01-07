#include <Server.h>


void Server::createServer(){

    socket_conn = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(socket_conn == -1){
        cout << "Socket Failed";
    }

    if(bind(socket_conn, (struct sockaddr*)&address, sizeof(address)) == -1){
        cout << "Bind Failed";
    }
}

void Server::listenServer(){
    if(listen(socket_conn, 1) == -1){
        cout << "Listen Failed";
    }

    socket_conn = accept(socket_conn, (struct sockaddr*)&address, (socklen_t*)(sizeof(address)));

    if(socket_conn == -1){
        cout << "Accept Failed";
    }
}

void Server::readServer(char *buffer){

    read(socket_conn, buffer, sizeof(buffer));

}

void Server::sendServer(char *buffer){

    send(socket_conn, buffer, sizeof(buffer), 0);

}

void Server::pingServer(){
    while(true){

        unique_ptr<Server> server(new Server);
        char *buffer;
        server->readServer(buffer);

        cout << buffer << endl;

        char *buffer2 = "Hello client";

        server->sendServer(buffer2);
        
    }
}