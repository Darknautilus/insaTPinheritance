// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "Executor.h"
#include "Controller.h"

Controller::Controller()
{
	currAction = actions.rbegin();
}

Controller::~Controller()
{
	if(DEBUG)
		std::cout << "Controller destroyed" << std::endl;
	for(std::list<Command*>::iterator it = actions.begin();
			it != actions.end();
			++it)
	{
		delete *it;
	}
}

bool Controller::Add(std::string pName, GeoElt *pElement, FileCommand *pFCommand)
{
	std::vector<std::string> names;
	names.push_back(pName);
	std::vector<GeoElt*> elements;
	elements.push_back(pElement);
	AddCommand *command = new AddCommand(&model, names, elements);
	if(pFCommand == 0)
	{
		bool commandValid = command->Do();
		if(commandValid)
		{
			if(currAction != actions.rbegin())
			{
				for(std::list<Command*>::reverse_iterator it = actions.rbegin();
						it != currAction;
						++it)
				{
					delete *it;
				}
				--currAction;
				actions.erase(--(currAction.base()),actions.end());
			}
			actions.push_back(command);
			currAction = actions.rbegin();
		}
		return commandValid;
	}
	else
	{
		return pFCommand->Add(command);
	}
}

bool Controller::Delete(std::vector<std::string> pNames, FileCommand *pFCommand)
{
	DeleteCommand *command = new DeleteCommand(&model, pNames);
	if(pFCommand == 0)
	{
		bool commandValid = command->Do();
		if(commandValid)
		{
			if(currAction != actions.rbegin())
			{
				for(std::list<Command*>::reverse_iterator it = actions.rbegin();
						it != currAction;
						++it)
				{
					delete *it;
				}
				--currAction;
				actions.erase(--(currAction.base()),actions.end());
			}
			actions.push_back(command);
			currAction = actions.rbegin();
		}
		return commandValid;
	}
	else
	{
		return pFCommand->Add(command);
	}
}

bool Controller::Move(std::string pName, Point *pDirection, FileCommand *pFCommand)
{
	std::vector<std::string> names;
	names.push_back(pName);
	MoveCommand *command = new MoveCommand(&model, names, pDirection);
	if(pFCommand == 0)
	{
		bool commandValid = command->Do();
		if(commandValid)
		{
			if(currAction != actions.rbegin())
			{
				for(std::list<Command*>::reverse_iterator it = actions.rbegin();
						it != currAction;
						++it)
				{
					delete *it;
				}
				--currAction;
				actions.erase(--(currAction.base()),actions.end());
			}
			actions.push_back(command);
			currAction = actions.rbegin();
		}
		return commandValid;
	}
	else
	{
		return pFCommand->Add(command);
	}
}

bool Controller::LoadFromFile(std::string pFilename, Interpreter *pInterpreter, Executor *pExecutor)
{
	FileCommand *command;
	CommandFeedback *feedback;
	std::ifstream inputFile(pFilename);
	std::string line;
	if(inputFile.good())
	{
		command = new FileCommand(&model);
		std::getline(inputFile,line);
		while(!inputFile.eof() && !inputFile.fail())
		{
			feedback = pInterpreter->Read(line);
			pExecutor->Execute(feedback, command);
			delete feedback;
			std::getline(inputFile,line);
		}
		bool failed = !inputFile.eof();
		inputFile.close();
		if(failed)
		{
			delete command;
			return false;
		}
		bool commandValid = command->Do();
		if(commandValid)
		{
			if(currAction != actions.rbegin())
			{
				for(std::list<Command*>::reverse_iterator it = actions.rbegin();
						it != currAction;
						++it)
				{
					delete *it;
				}
				--currAction;
				actions.erase(--(currAction.base()),actions.end());
			}
			actions.push_back(command);
			currAction = actions.rbegin();
		}
		return commandValid;
	}
	else
	{
		return false;
	}
}

bool Controller::SaveInFile(std::string pFilename)
{
	return model.SaveInFile(pFilename);
}

bool Controller::Undo()
{
	if(currAction == actions.rend())
	{
		return false;
	}
	else
	{
		bool ret = (*currAction)->Undo();
		if(ret)
			++currAction;
		return ret;
	}
}

bool Controller::Redo()
{
	if(currAction == actions.rbegin())
	{
		return false;
	}
	else
	{
		--currAction;
		bool ret = (*currAction)->Do();
		if(!ret)
			++currAction;
		return ret;
	}
}

void Controller::List()
{
	model.List();
}

void Controller::Clear()
{
	for(std::list<Command*>::iterator it = actions.begin();
			it != actions.end();
			++it)
	{
		delete *it;
	}
	actions.clear();
	currAction = actions.rbegin();
	model.Clear();
}

GeoElt *Controller::Exists(std::string pName)
{
	return model.Exists(pName);
}
