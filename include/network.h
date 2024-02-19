
#ifndef NETWORK_H
#define NETWORK_H

#include <stdint.h>
#include <stddef.h> 
#include <sys/types.h>
#include <stdbool.h>

// Function to establish a TCP connection to a remote host
int tcp_connect(const char* host, uint16_t port);

// Function to send data over a TCP connection
bool tcp_send(int socket_fd, const void* data, size_t size);

// Function to receive data from a TCP connection
ssize_t tcp_receive(int socket_fd, void* buffer, size_t buffer_size);

// Function to close a TCP connection
void tcp_close(int socket_fd);

#endif 

