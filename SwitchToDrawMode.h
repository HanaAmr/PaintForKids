#pragma once
#include"Actions/Action.h"

#ifndef SwitchToDrawMode_h
#define SwitchToDrawMode_h


class SwitchToDrawMode :public Action
{
public:
	//constuctor
	SwitchToDrawMode(ApplicationManager *pApp);

	//destructor
	~SwitchToDrawMode();

	//get users click on switch_to_play_mode icon to execute
	virtual void ReadActionParameters();

	//exit from program
	virtual void Execute();


};

#endif