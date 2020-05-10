#pragma once
#include "Actions/Action.h"

class AddEllipseAction : public Action
{
private:
	Point P1; //Ellipse Center
	GfxInfo EllipseGfxInfo;
public:
	AddEllipseAction(ApplicationManager *pApp);

	//Reads ellipse parameters
	virtual void ReadActionParameters();

	//Add ellipse to the ApplicationManager
	virtual void Execute();

};

