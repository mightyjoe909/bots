#include "messageInterface.h"

//Mother Bot
int InitSever()
{
	/* Create the socket and set it up to accept connections. */
	sock = make_socket (PORT);
	if (listen (sock, 1) < 0)
	{
		perror ("listen");
		exit (EXIT_FAILURE);
	}

	/* Initialize the set of active sockets. */
	FD_ZERO (&active_fd_set);
	FD_SET (sock, &active_fd_set);
	bots = 0;
	return 0;
}

int CheckForNewBot()
{
	fprintf(stderr, "in Check For Bot\n");
	struct timeval tv = {1, 0};
	/* Block until input arrives on one or more active sockets. */
	read_fd_set = active_fd_set;
	if (select (FD_SETSIZE, &read_fd_set, NULL, NULL, &tv) < 0)
	{
		perror ("select");
		exit (EXIT_FAILURE);
	}

	/* Service all the sockets with input pending. */
	for (i = 0; i < FD_SETSIZE; ++i)
	{
		if (FD_ISSET (i, &read_fd_set))
		{
			if (i == sock)
			{
				/* Connection request on original socket. */
				size = sizeof (clientname);
				connection[bots][0] = accept (sock,
									(struct sockaddr *) &clientname,
									&size);
				if (connection[bots] < 0)
				{
					perror ("accept");
					exit (EXIT_FAILURE);
				}
				fprintf (stderr,
					"Server: connect from host %s, port %hd.\n",
					inet_ntoa (clientname.sin_addr),
					ntohs (clientname.sin_port));
				FD_SET (connection[bots], &active_fd_set);
				bots++;
			}
			else
			{
				/* Data arriving on an already-connected socket. */
				if (GetStatus (i) < 0)
				{
					close (i);
					FD_CLR (i, &active_fd_set);
				}
			}
		}
	}
	
	return bots;
}

int GetStatus(int filedes)
{
	fprintf(stderr, "in Get Status\n");
	char buffer[MAXMSG];
	int nbytes;
	printf("filedes: %d\n", filedes);
	nbytes = read (filedes, buffer, MAXMSG);
	if (nbytes < 0)
	{
	  /* Read error. */
	  perror ("read");
	  exit (EXIT_FAILURE);
	}
	else if (nbytes == 0)
	/* End-of-file. */
	return -1;
	else
	{
	  /* Data read. */
	  fprintf (stderr, "Server: got message: `%s'\n", buffer);
          connection[filedes][1] = (buffer[0]  - '0');
	  //sendMessage(filedes);
	  return 0;
	}
}

int make_socket(uint16_t port)
{
	int sock;
	struct sockaddr_in name;

	/* Create the socket. */
	sock = socket (PF_INET, SOCK_STREAM, 0);
	if (sock < 0)
	{
	  perror ("socket");
	  exit (EXIT_FAILURE);
	}

	/* Give the socket a name. */
	name.sin_family = AF_INET;
	name.sin_port = htons (port);
	name.sin_addr.s_addr = htonl (INADDR_ANY);
	if (bind (sock, (struct sockaddr *) &name, sizeof (name)) < 0)
	{
	  perror ("bind");
	  exit (EXIT_FAILURE);
	}

	return sock;
}

//Bots
int getMessage()
{
	fprintf(stderr, "in getMessage\n");
	return debug;
}

int sendStatus()
{
	fprintf(stderr, "in sendStatus\n");
	return debug;
}