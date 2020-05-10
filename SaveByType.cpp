#include"SaveByType.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"


SaveByType::SaveByType(ApplicationManager *pApp) :Action(pApp)
{}


void SaveByType::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces

	Output* pOut = pManager->GetOutput();

	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Please choose a figure type from toolbar.");



}




void SaveByType::Execute()
{
	Output* pOut = pManager->GetOutput();

	Input* pIn = pManager->GetInput();

	ReadActionParameters();


	ActionType Action = pIn->GetUserAction();

	if (Action != 0 && Action != 1 && Action != 2 && Action != 3 && Action != 4)
		pOut->PrintMessage("Invalid! You didn't choose a figure type!");

	else
	{
		pOut->PrintMessage("Enter file name:");

		fileName = pIn->GetString(pOut) + ".txt";

		pOut->ClearStatusBar();

		OutputFile.open(fileName);


		//check if the file is opened
		if (OutputFile.is_open())
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

			pManager->Save_By_Type(Action, OutputFile);
			pOut->PrintMessage("Your file has been saved.");
			OutputFile.close();
		}

		else
		{
			pOut->PrintMessage("Unable to save file.");
		}
	}


}


