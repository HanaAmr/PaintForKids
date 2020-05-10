#pragma once
#include "Actions/Action.h"
class AddRhombusAction : public Action
{

private:
	Point P1; //Rhombus Center
	GfxInfo RhombusGfxInfo;
public:
	AddRhombusAction(ApplicationManager *pApp);

	//Reads rhombus parameters
	virtual void ReadActionParameters();

	//Add rhombus to the ApplicationManager
	virtual void Execute();

};

