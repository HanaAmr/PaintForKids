#pragma once
#include "Actions/Action.h"
class Resize : public Action
{
	float ScalingFactor;
public:
	Resize(ApplicationManager * pApp);
	void ReadActionParameters();
	void Execute();
	~Resize();
};

