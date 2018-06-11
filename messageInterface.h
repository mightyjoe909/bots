#ifndef MESSAGEINTER_H
#define MESSAGEINTER_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "motherBot.h"
#include "bot.h"

#define PORT    8080
#define MAXMSG  512

int sock;
fd_set active_fd_set, read_fd_set;
int i;
struct sockaddr_in clientname;
size_t size;

//Mother Bot
int CheckForNewBot(void);
int GetStatus(int);
int InitSever(void);
int make_socket(uint16_t port);

//Bots
int getMessage(void);
int sendStatus(void);

//Common
int inet_ntoa(struct in_addr);
int cleanup(void);
int connection[64][5];
int bots;

#endif