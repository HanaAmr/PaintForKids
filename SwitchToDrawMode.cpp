#include"SwitchToDrawMode.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI\Output.h"

//constuctor
SwitchToDrawMode::SwitchToDrawMode(ApplicationManager *pApp) :Action(pApp)
{

}

//destructor
SwitchToDrawMode::~SwitchToDrawMode()
{

}
//get users click on switch_to_play_mode icon to execute
void SwitchToDrawMode::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("You have clicked on switch to draw mode");
	pOut->CreateDrawToolBar();
}



void SwitchToDrawMode::Execute()
{

	ReadActionParameters();
	Output*pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->UpdateInterface();

}

