// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <stdexcept>

#include "Config.h"

#include "Agregated.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"
#include "Polyline.h"

class Controller;
class Interpreter;
class CommandFeedback;
class FileCommand;

/**
 * Exécuteur de commandes. Deuxième maillon de la chaîne d'interprétation de commandes, l'exécuteur est chargé d'effectuer les contrôles plus poussés sur la commande et surtout de l'exécuter et de traiter les éventuelles erreurs.
 */
class Executor
{
	public:
		Executor(Interpreter*);
		virtual ~Executor();

		/**
		 * Exécute la commande. Donne les instructions au contrôleur pour exécuter la commande
		 * \param feedback Le rapport donné par l'interpréteur
		 * \param file Le buffer de chargement en cas de chargement de fichier
		 * \return false si la commande est EXIT (sortie de programme) et true sinon
		 */
		bool Execute(CommandFeedback *feedback,FileCommand *file= 0);

	private:
		Interpreter *interpreter;
		Controller *controller;
};

#endif
