#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "AddCommand.h"
#include "DeleteCommand.h"
#include "MoveCommand.h"

class Controller
{
	public:
		Controller();
		virtual ~Controller();

		bool Add(std::string,GeoElt*);
		bool Delete(std::string);
		bool Move(std::string,Point*);
		bool SaveInFile(std::string);
		bool Undo();
		bool Redo();

	protected:
		std::list<Command*> actions;
		std::list<Command*>::reverse_iterator currAction;
		Model model;

};

#endif
