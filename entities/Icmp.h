#ifndef ICMP_H
#define ICMP_H


struct Icmp
{
    char type;
    char code;
    char checksum;
};


void encode(char *buffer, Icmp icmp){
    buffer[0] = icmp.type + '0';
}

void decode(Icmp icmp, char *buffer){
    icmp.type = buffer[0] - '0';
}





#endif