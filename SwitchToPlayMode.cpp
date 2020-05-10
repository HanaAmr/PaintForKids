#include"SwitchToPlayMode.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI\Output.h"


//constuctor
SwitchToPlayMode::SwitchToPlayMode(ApplicationManager *pApp) :Action(pApp)
{

}

//destructor
SwitchToPlayMode::~SwitchToPlayMode()
{

}

//get users click on switch_to_play_mode icon to execute
void SwitchToPlayMode::ReadActionParameters()
{

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	CFigure* UnSelectFig = pManager->getSelected();
	if (UnSelectFig != NULL)
	{
		UnSelectFig->SetSelected(false);
		UnSelectFig = NULL;
	}
	pOut->PrintMessage("You have clicked on switch to play mode");
	pOut->CreatePlayToolBar();
}


void SwitchToPlayMode::Execute()
{
	ReadActionParameters();

}

