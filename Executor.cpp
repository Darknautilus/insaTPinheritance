// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "Controller.h"
#include "Executor.h"

#include <stdexcept>

Executor::Executor(Interpreter *pInterpreter) : interpreter(pInterpreter)
{
	controller = new Controller();
}

Executor::~Executor()
{
	delete controller;
}

bool Executor::Execute(CommandFeedback *feedback, FileCommand *pFCommand)
{
	if(feedback->Status == CommandStatus::OK)
	{
		if(feedback->Code == CommandCode::EXIT)
		{
			return false;
		}
		else if(feedback->Code == CommandCode::CLEAR)
		{
			if(pFCommand == 0)
			{
				controller->Clear();
				printStatus(feedback->Status);
			}
		}
		else if(feedback->Code == CommandCode::UNDO)
		{
			if(pFCommand == 0)
			{
				controller->Undo();
				printStatus(feedback->Status);
			}
		}
		else if(feedback->Code == CommandCode::REDO)
		{
			if(pFCommand == 0)
			{
				controller->Redo();
				printStatus(feedback->Status);
			}
		}
		else if(feedback->Code == CommandCode::LIST)
		{
			controller->List();
		}
		else if(feedback->Code == CommandCode::SAVE)
		{
			if(pFCommand == 0 && std::ifstream(feedback->Args.front()).good())
			{
				std::cout << "Fichier exitant, écraser ? (o/N)";
				string input;
				std::getline(std::cin,input);
				if(input.compare("o") == 0)
				{
					if(controller->SaveInFile(feedback->Args.front()))
					{
						printStatus(feedback->Status);
					}
					else
					{
						std::cout << "Error" << std::endl;
					}
				}
			}
		}
		else if(feedback->Code == CommandCode::LOAD)
		{
			if(pFCommand == 0)
			{
				if(std::ifstream(feedback->Args.front()).good())
				{
					if(controller->LoadFromFile(feedback->Args.front(), interpreter, this))
					{
						printStatus(feedback->Status);
					}
					else
					{
						std::cout << "Error 2" << std::endl;
					}
				}
				else
				{
					std::cout << "Error 1" << std::endl;
				}
			}
		}
		else if(feedback->Code == CommandCode::MOVE)
		{
			int x,y;
			bool isInt = true;
			try
			{
				x = std::stoi(feedback->Args[1]);
				y = std::stoi(feedback->Args[2]);
			}
			catch(std::invalid_argument ia)
			{
				isInt = false;
			}
			catch(std::out_of_range oor)
			{
				isInt = false;
			}
			if(isInt)
			{
				Point direction(x,y);
				bool moved = controller->Move(feedback->Args[0],&direction,pFCommand);
				if(pFCommand == 0 && moved)
				{
					printStatus(feedback->Status);
				}
			}
			else
			{
				std::cout << "Error" << std::endl;
			}
		}
		else if(feedback->Code == CommandCode::DELETE)
		{
			if(!feedback->Args.empty())
			{
				std::vector<std::string> names;
				for(int i = 0; i < feedback->Args.size(); i++)
				{
					names.push_back(feedback->Args.at(i));
				}
				bool deleted = controller->Delete(names,pFCommand);
				if(pFCommand == 0 && deleted)
				{
					printStatus(feedback->Status);
				}
			}
			else
			{
				std::cout << "Vide" << std::endl;
			}
		}
	}
	else
	{
		printStatus(feedback->Status);
	}
	return true;
}
