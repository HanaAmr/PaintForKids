#pragma once
#ifndef PickByColor_h
#define PickByColor_h

#include"Actions/Action.h"


class PickByColor :public Action
{
	int  FiguresCount;
	int CorrectCount;
	int FalseCount;
	int RedCount;
	int WhiteCount;
	int BlackCount;
	int GreenCount;
	int BlueCount;
	int random;
	int PickedType;
	string Message;

public:

	PickByColor(ApplicationManager * pApp);

	~PickByColor();

	virtual void ReadActionParameters();

	virtual void Execute();

};

#endif