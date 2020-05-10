#pragma once
#include "Select.h"
#include "ApplicationManager.h"
#include "Actions/Action.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "Copy.h"
#include "Cut.h"


class Paste :public Action {
	Point P1;
public:
	Paste(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

	~Paste();

};

