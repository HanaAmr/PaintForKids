#include"SaveGraph.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"


SaveGraph::SaveGraph(ApplicationManager *pApp) :Action(pApp)
{}

//Read the parameters for the save action 
void SaveGraph::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces

	Output* pOut = pManager->GetOutput();

	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter file name:");


	fileName = pIn->GetString(pOut) + ".txt";

	pOut->ClearStatusBar();

	OutputFile.open(fileName);

	//check if the file is opened
	if (OutputFile.is_open())
	{
		pOut->PrintMessage("Your file has been saved.");
	}

	else
	{
		pOut->PrintMessage("Unable to save file.");
	}
}


void SaveGraph::Execute()
{
	ReadActionParameters();

	if (OutputFile.is_open()) 	//check if the file is opened
	{
		string DrawColor, FillColor;

		
		if (UI.DrawColor == BLACK)
			DrawColor = "BLACK";
		if (UI.DrawColor == RED)
			DrawColor = "RED";
		if (UI.DrawColor == GREEN)
			DrawColor = "GREEN";
		if (UI.DrawColor == BLUE)
			DrawColor = "BLUE";
		if (UI.DrawColor == WHITE)
			DrawColor = "WHITE";

		if (UI.FillColor == BLACK)
			FillColor = "BLACK";
		if (UI.FillColor == RED)
			FillColor = "RED";
		if (UI.FillColor == GREEN)
			FillColor = "GREEN";
		if (UI.FillColor == BLUE)
			FillColor = "BLUE";
		if (UI.FillColor == WHITE)
			FillColor = "WHITE";

		OutputFile << DrawColor << " " << FillColor << endl;

		OutputFile << pManager->getFigCount() << endl;

		//calling the function saveAll in the application manager 

		pManager->SaveAll(OutputFile);

		//close the file after saving

		OutputFile.close();
	}
}

