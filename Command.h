#ifndef COMMAND_H
#define COMMAND_H

#include "Model.h"
#include "GeoElt.h"

class Command
{
	public:
		Command(Model*,std::string,GeoElt*);
		virtual ~Command();

		virtual bool Do() = 0;
		virtual bool Undo() = 0;

	protected:
		Model *model;
		GeoElt *element;
		std::string eltName;
};

#endif
