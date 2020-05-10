#pragma once
#include "Actions/Action.h"
class ChngDrawClrAction : public Action
{
	color C;
	int test;
public:
	ChngDrawClrAction(ApplicationManager * pApp);
	void ReadActionParameters();
	void Execute();

	~ChngDrawClrAction();
};

