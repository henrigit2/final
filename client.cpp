#include <iostream>
#include "actions/Client.h"

using namespace std;

int main(){

    Client client;

    client.createClient();
    client.connectClient();
    client.pingClient();

    client.closeClient();

    

    return 0;
}