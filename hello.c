#include <stdio.h>
#include "server.h"
char buffer[MAXMSG];
static int setFlag = 0;
int inputAvailable()  
{
  struct timeval tv;
  fd_set fds;
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);
  select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
  
  int nbytes;
  if(FD_ISSET(0, &fds))
  {
	nbytes = read (STDIN_FILENO+1, buffer, MAXMSG);
	fprintf (stderr, "send message to client: `%s'\n", buffer);
	setFlag = 1;
  }
  return (FD_ISSET(0, &fds));
}

int main(int argcc, char *argv[])
{
	int in = 0;
	int y;
printf("hello joe\n");
static int last_connection = -1;
init();

while(buffer[0] != 'q')
{
	
	//puts("looping\n");
	in = inputAvailable();
	//puts(buffer);
	int x = getMessage();
	if(new > 0)
	{
		if (new != last_connection)
		{
			if (FD_ISSET (new, &read_fd_set))
			{
				//y = sendMessage(new);
			}
			last_connection = new;
			
			for(int i = 0; i < new; i++)
			{
				fprintf(stderr, "connected: %d\n", connection[i]);
			}
		}
		if(setFlag)
		{
			y = sendMessage(buffer[0] - '0');
			fprintf(stderr, "selected: %d\n", buffer[0] - '0');
			setFlag = 0;
		}
	}
}

cleanup();

}