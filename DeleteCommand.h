#ifndef DELETECOMMAND_H
#define DELETECOMMAND_H

#include "Command.h"

class DeleteCommand : public Command
{
	public:
		DeleteCommand(Model*,std::string);
		virtual ~DeleteCommand();

		bool Do();
		bool Undo();

};

#endif
