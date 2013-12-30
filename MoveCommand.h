#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "Command.h"

class MoveCommand : public Command
{
	public:
		MoveCommand(Model*,std::string,Point*);
		virtual ~MoveCommand();

		bool Do();
		bool Undo();

	protected:
		Point *direction;

};

#endif
