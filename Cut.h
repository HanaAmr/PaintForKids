#pragma once
#include "Select.h"
#include "ApplicationManager.h"
#include "Actions/Action.h"
#include "GUI\input.h"
#include "GUI\Output.h"

class Cut : public Action {
private:

public:
	Cut(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

	~Cut();

};

