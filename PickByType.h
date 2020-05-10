#pragma once
#ifndef PickByType_h
#define PickByType_h

#include"Actions/Action.h"


class PickByType :public Action
{
	int  FiguresCount;
	int CorrectCount;
	int FalseCount;
	int EllipseCount;
	int RectangleCount;
	int TriangleCount;
	int LineCount;
	int RhombusCount;
	int random;
	int PickedType;
	string Message;
	
public:

	PickByType(ApplicationManager * pApp);

	~PickByType();

	virtual void ReadActionParameters();

	virtual void Execute();

};

#endif