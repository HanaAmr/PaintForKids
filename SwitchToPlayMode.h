#pragma once
#ifndef SwitchToPlayMode_h
#define SwitchToPlayMode_h

#include"Actions/Action.h"

class SwitchToPlayMode :public Action
{
public:
	//constuctor
	SwitchToPlayMode(ApplicationManager *pApp);
	~SwitchToPlayMode();

	//get users click on switch_to_play_mode icon to execute
	virtual void ReadActionParameters();

	//exit from program
	virtual void Execute();


};

#endif
