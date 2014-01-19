// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef COMMAND_H
#define COMMAND_H

#include <vector>

#include "Model.h"
#include "GeoElt.h"

class Command
{
	public:
		Command(Model*);
		Command(Model*,std::vector<std::string>&);
		Command(Model*,std::vector<std::string>&,std::vector<GeoElt*>&);
		virtual ~Command();

		virtual bool Do() = 0;
		virtual bool Undo() = 0;

	protected:
		Model *model;
		std::vector<GeoElt*> elements;
		std::vector<std::string> names;
};

#endif
