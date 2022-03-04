#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define REQUEST 4 /* max size of request in bytes */
#define REPLY   4 /* max size of reply in bytes */

#define UDP_SERV_PORT 7777 /* UDP server's well known port */
#define TCP_SERV_PORT 8888 /* TCP server's well known port */
#define TTCP_SERV_PORT 9999 /* T/TCP server's well known port */

// shorten all type casts of pointer arguments
// define SA to be a struct sockaddr pointer to a generic socket address structure
// Commonly abbreviated due to page width issues since this pattern dates back to the early 1980s
// This abbreviation is borrowed from BSD kernel sources
#define SA struct sockaddr *

void read_stream(int, char *, int);
