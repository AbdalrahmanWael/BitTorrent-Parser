#ifndef PEER_H
#define PEER_H

#include <stdint.h>
#include <netinet/in.h> 

// Structure to represent information about a peer
typedef struct PeerInfo {
    char ip[INET6_ADDRSTRLEN];  // IP address of the peer
    uint16_t port;               // Port number of the peer
} PeerInfo;

// Function to establish a connection with a peer
int connect_to_peer(const char* ip, uint16_t port);

// Function to handle communication with a peer
void communicate_with_peer(int peer_socket);

#endif 
