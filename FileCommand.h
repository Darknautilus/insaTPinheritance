// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef FILECOMMAND_H
#define FILECOMMAND_H

#include "Command.h"

class FileCommand : public Command
{
	public:
		FileCommand(Model*);
		virtual ~FileCommand();

		bool Add(Command*);

		bool Do();
		bool Undo();

	private:
		std::list<Command*> commands;
		std::list<int> errors;
};

#endif
