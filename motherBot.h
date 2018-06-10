#ifndef MBOT_H
#define MBOT_H

#include <stdio.h>
#include "messageInterface.h"
#include "commandInterface.h"

#define debug 1;

static int numberofBots = 0;
static int sendCommands = 0;
static int getStatus = 0;
static int updateModel = 0;
int botID;

int InitMother(void);
int UpdateModel(void);

#endif