#include "MoveCommand.h"

MoveCommand::MoveCommand(Model *pModel, std::string pName, Point *pDirection) : Command(pModel,pName,NULL), direction(pDirection)
{
}

MoveCommand::~MoveCommand()
{
}

bool MoveCommand::Do()
{
	return model->Move(eltName,direction);
}

bool MoveCommand::Undo()
{
	return model->Move(eltName,direction->Inverse());
}
