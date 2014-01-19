// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "Command.h"

class MoveCommand : public Command
{
	public:
		MoveCommand(Model*,std::vector<std::string>&,Point*);
		virtual ~MoveCommand();

		bool Do();
		bool Undo();

	protected:
		Point *direction;

};

#endif
