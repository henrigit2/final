#include <iostream>
#include "actions/Server.h"

using namespace std;

int main(){

    Server server;

    server.createServer();
    server.listenServer();
    server.pingServer();
    
    server.closeServer();

    return 0;
}