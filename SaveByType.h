#pragma once
#include "Actions/Action.h"

#include<fstream>



class SaveByType :public Action
{
	ofstream OutputFile;
	string fileName;
public:

	SaveByType(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();


};