// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <fstream>

#include "Config.h"

#include "AddCommand.h"
#include "DeleteCommand.h"
#include "MoveCommand.h"
#include "FileCommand.h"

#include "Interpreter.h"

class Executor;

class Controller
{
	public:
		Controller();
		virtual ~Controller();

		bool Add(std::string,GeoElt*,FileCommand* = 0);
		bool Delete(std::vector<std::string>,FileCommand* = 0);
		bool Move(std::string,Point*,FileCommand* = 0);
		bool LoadFromFile(std::string, Interpreter*, Executor*);
		bool SaveInFile(std::string);
		bool Undo();
		bool Redo();
		void List();
		void Clear();
		/**
		 * Vérifie que le nom donné existe. Vérifie dans le modèle que l'élément spécifié par son nom existe.
		 *
		 * \param name Le nom de l'élément
		 * \return Un pointeur vers l'élément s'il existe et 0 sinon.
		 * \sa Model::Exists()
		 */
		GeoElt *Exists(std::string name);

	protected:
		std::list<Command*> actions;
		std::list<Command*>::reverse_iterator currAction;
		Model model;

};

#endif
