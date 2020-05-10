#pragma once
#include "Select.h"
#include "ApplicationManager.h"
#include "Actions/Action.h"
#include "GUI\input.h"
#include "GUI\Output.h"

class Copy : public Action {
private:

public:
	Copy(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

	~Copy();

};
