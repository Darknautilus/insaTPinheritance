// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "FileCommand.h"

FileCommand::FileCommand(Model *pModel) : Command(pModel)
{}

FileCommand::~FileCommand()
{
	if(DEBUG)
		std::cout << "\tDestoying FileCommand" << std::endl;
	for(std::list<Command*>::iterator it = commands.begin();
			it != commands.end();
			++it)
	{
		if(DEBUG)
			std::cout << "\t";
		delete *it;
	}
	if(DEBUG)
		std::cout << "\tdestoyed" << std::endl;
}

bool FileCommand::Add(Command *pCommand)
{
	commands.push_back(pCommand);
	return true;
}

bool FileCommand::Do()
{
	int indice = 0;
	for(std::list<Command*>::iterator it = commands.begin();
			it != commands.end();
			++it)
	{
		if(!(*it)->Do())
		{
			errors.push_back(indice);
		}
		indice++;
	}
	if(errors.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool FileCommand::Undo()
{
	int indice = 0;
	std::list<int>::iterator itInd = errors.begin();
	for(std::list<Command*>::iterator it = commands.begin();
			it != commands.end();
			++it)
	{
		if(itInd != errors.end() && indice == *itInd)
		{
			itInd++;
		}
		else
		{
			(*it)->Undo();
		}
		indice++;
	}
	return true;
}
