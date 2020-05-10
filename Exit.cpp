#include"Exit.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"




Exit::Exit(ApplicationManager *pApp) :Action(pApp)
{

}
Exit::~Exit()
{

}
//get users click on exit icon to execute
void Exit::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	//Input* pIn = pManager->GetInput();

	pOut->PrintMessage("You have clicked on Exit");
	pOut->PrintMessage("Goodbye ");

}

//exit from program
void Exit::Execute()
{
	pManager->~ApplicationManager();
	ReadActionParameters();
}