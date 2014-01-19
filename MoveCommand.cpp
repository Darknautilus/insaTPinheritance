// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#include "MoveCommand.h"

MoveCommand::MoveCommand(Model *pModel, std::vector<std::string>& pNames, Point *pDirection) : Command(pModel,pNames), direction(pDirection)
{
}

MoveCommand::~MoveCommand()
{
	if(DEBUG)
		std::cout << "\tMoveCommand destroyed" << std::endl;
}

bool MoveCommand::Do()
{
	return model->Move(names.front(),direction) != 0;
}

bool MoveCommand::Undo()
{
	return model->Move(names.front(),direction->Inverse()) != 0;
}
