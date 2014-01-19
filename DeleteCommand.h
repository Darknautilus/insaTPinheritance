// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef DELETECOMMAND_H
#define DELETECOMMAND_H

#include "Command.h"

class DeleteCommand : public Command
{
	public:
		DeleteCommand(Model*,std::vector<std::string>&);
		virtual ~DeleteCommand();

		bool Do();
		bool Undo();

};

#endif
