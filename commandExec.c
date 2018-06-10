#include "commandInterface.h"

//Mother Bot
int SendCommands(int filedes)
{
	fprintf(stderr, "in Send Command\n");
	char *hello = "Hello from server";
	send(filedes , hello , strlen(hello) , 0 );
	return debug;
}

//Bots
int doCommand()
{
	fprintf(stderr, "in doCommand\n");
	return debug;
}