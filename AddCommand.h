#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include "Command.h"

class AddCommand : public Command
{
	public:
		AddCommand(Model*,std::string,GeoElt*);
		virtual ~AddCommand();

		bool Do();
		bool Undo();

};

#endif
