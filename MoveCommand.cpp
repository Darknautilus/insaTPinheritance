// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "MoveCommand.h"

int MoveCommand::commandId = 0;

MoveCommand::MoveCommand(Model *pModel, std::vector<std::string>& pNames, Point pDirection) : Command(pModel,pNames), direction(pDirection)
{
}

MoveCommand::~MoveCommand()
{
	if(DEBUG)
		std::cout << "\tMoveCommand destroyed" << std::endl;
}

bool MoveCommand::Do()
{
	commandId++;
	if(DEBUG)
		std::cout << "--> " << direction << std::endl;
	return model->Move(names.front(),&direction,commandId) != 0;
}

bool MoveCommand::Undo()
{
	commandId--;
	if(DEBUG)
		std::cout << direction << " --> " << *(direction.Inverse()) << std::endl;
	return model->Move(names.front(),direction.Inverse(),commandId) != 0;
}
