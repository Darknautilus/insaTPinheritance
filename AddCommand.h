// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include "Command.h"

class AddCommand : public Command
{
	public:
		AddCommand(Model*,std::vector<std::string>&,std::vector<GeoElt*>&);
		virtual ~AddCommand();

		bool Do();
		bool Undo();
	
	protected:
		bool done;
};

#endif
