#ifndef SERVER_H
#define SERVER_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#define PORT    8080
#define MAXMSG  512

int sock;
fd_set active_fd_set, read_fd_set;
int i;
struct sockaddr_in clientname;
size_t size;

int getMessage(void);
int sendMessage(int);
int inet_ntoa(struct in_addr);
int make_socket(uint16_t port);
int init(void);
int cleanup(void);
int connection[64];
int new;
int read_from_client(int);

#endif