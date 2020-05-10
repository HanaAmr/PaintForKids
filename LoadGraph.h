#pragma once
#include "Actions/Action.h"

#include<fstream>


class LoadGraph : public Action
{
	ifstream InputFile;

	string fileName;


public:

	LoadGraph(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

