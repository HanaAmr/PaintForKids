#pragma once
#include "Actions/Action.h"
class BringtoBack_Front : public Action
{
public:
	BringtoBack_Front(ApplicationManager * pApp);
	void ReadActionParameters();
	void Execute();
	~BringtoBack_Front();
};

