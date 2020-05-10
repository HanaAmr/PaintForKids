#pragma once
#include "Actions/Action.h"

#include<fstream>


class SaveGraph :public Action
{
	ofstream OutputFile;
	string fileName;
public:

	SaveGraph(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

