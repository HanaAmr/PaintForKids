#pragma once
#include "Actions/Action.h"
class ChngFillClrAction : public Action
{
	color C;
	int test;
public:
	ChngFillClrAction(ApplicationManager * pApp);
	void ReadActionParameters();
	void Execute();
	~ChngFillClrAction();
};

