#include "bot.h"

// Function init(void)
// Purpose: Initize the bot
// Input: none
// Output: (int) status
int InitBot()
{
	fprintf(stderr, "in init\n");
	return debug;
}

// Function main(void)
// Purpose: Main entry to bot
// Input: none
// Output: (int)status
int main(void)
{
	static int myStatus = 0;
	static int getMessageStatus = 0;
	static int doCmdStatus = 0;
	static int SendStatus = 0;
	
	//Initize the bot
	myStatus = InitBot();
	
	//Main bot loop; will break if anything fails or if init failed
	while(myStatus)
	{
		//Get Message from Master
		getMessageStatus = getMessage();
		
		//Do the next command in the list
		doCmdStatus = doCommand();
		
		//Send a status message to the master
		SendStatus = sendStatus();
		
		///Check to see if anything failed
		myStatus = getMessageStatus & 
					doCmdStatus & 
					SendStatus;
					
		fprintf(stderr, "myStatus = %d\n", myStatus);
	}

}