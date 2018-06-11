#include "motherBot.h"

// Function init(void)
// Purpose: Initize the Mother Bot
// Input: none
// Output: (int) status
int InitMother()
{
	fprintf(stderr, "in init\n");
	InitSever();
	return debug;
}

int UpdateModel()
{
	fprintf(stderr, "in updateModel\n");
	return debug;
}

int main()
{	
	InitMother();
	
	while(numberofBots > 0)
	{
		numberofBots = CheckForNewBot();
		
		if(numberofBots > 0)
		{
                    for (int i = 0; i < numberofBots; i++)
                    {
			sendCommands   = SendCommands(i);
			getStatus      = GetStatus(i);	
                    }
                    updateModel    = UpdateModel();	
		}
	
	}
}