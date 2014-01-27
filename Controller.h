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

		/**
		 * Ajoute un élément.
		 * \param nom Le nom à donner à l'élément
		 * \param element L'élément à ajouter
		 * \param file cf. Executor::Execute()
		 * \return true si l'ajout s'est bien déroulé et false sinon
		 * \sa Model::Add()
		 */
		bool Add(std::string,GeoElt *element,FileCommand *file = 0);
		/**
		 * Supprime un ou plusieurs éléments.
		 * \param names Les noms des éléments à supprimer
		 * \param file cf. Controller::Add()
		 * \return true si la suppression s'est bien faite et false sinon
		 * \sa Model::Delete()
		 */
		bool Delete(std::vector<std::string> names,FileCommand *file = 0);
		/**
		 * Déplace un élément.
		 * \param name Le nom de l'élément à déplacer
		 * \param direction Le vecteur de translation
		 * \param file cd. Controller::Add()
		 * \return true si le déplacement s'est bien fait et false sinon
		 * \sa Model::Move()
		 */
		bool Move(std::string name,Point& direction,FileCommand *file = 0);
		/**
		 * Charge le fichier et interprète son contenu.
		 * \param filename Le nom du fichier à charger
		 * \param interpreter L'interpréteur à utiliser pour lire le contenu
		 * \param executor L'executeur à utiliser pour exécuter les commandes du fichier
		 * \return true si le chargement s'est bien déroulé et false sinon
		 * \sa Controller::SaveInFile()
		 */
		bool LoadFromFile(std::string filename, Interpreter *interpreter, Executor *executor);
		/**
		 * cf. Model::SaveInFile()
		 * \sa Controller::LoadFromFile()
		 */
		bool SaveInFile(std::string);
		bool Undo();
		bool Redo();
		void List();
		void Clear();
		/**
		 * Vérifie que le nom donné existe. Vérifie dans le modèle que l'élément spécifié par son nom existe.
		 *
		 * \param name Le nom de l'élément
		 * \param fileCommand Le FileCommand où chercher l'élément en cas d'ajout différé dans le modèle
		 * \return Un pointeur vers l'élément s'il existe et 0 sinon.
		 * \sa Model::Exists()
		 */
		GeoElt *Exists(std::string name, FileCommand *fileCommand = 0);

	protected:
		std::list<Command*> actions;
		std::list<Command*>::reverse_iterator currAction;
		Model model;

};

#endif
