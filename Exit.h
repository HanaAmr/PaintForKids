#pragma once
#include "Actions/Action.h"

#ifndef ExitAction_h
#define ExitAction_h

class Exit :public Action
{
public:
	//constuctor
	Exit(ApplicationManager *pApp);
	~Exit();
	//get users click on exit icon to execute
	virtual void ReadActionParameters();

	//exit from program
	virtual void Execute();

};

#endif

