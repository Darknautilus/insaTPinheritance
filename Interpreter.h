// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <string>
#include <list>
#include <deque>
#include <map>
#include <algorithm>
#include <sstream>
#include <iterator>

/**
 * Couche d'abstraction de commande. Donne un moyen d'identifier la commande entrée par l'utilisateur.
 */
enum CommandCode
{
	NULLC,///<Commande inconnue
	CIRCLE,
	RECTANGLE,
	LINE,
	POLYLINE,
	AO,///<Objet Agrégé
	DELETE,
	MOVE,
	LIST,
	UNDO,
	REDO,
	LOAD,
	SAVE,
	CLEAR,
	EXIT
};

/**
 * Résultat d'une commande. Donne le résultat de l'examen de la commande par l'interpréteur et l'exécuteur.
 */
enum CommandStatus
{
	OK,
	GENERIC_ERROR,///<N'importe quelle erreur de l'exécuteur
	BAD_COMMAND,
	BAD_PARAM_NB
};

inline void printMessage(std::string pMessage)
{
	std::cout << "#" << pMessage << std::endl;
}

inline void printStatus(CommandStatus pStatus)
{
	if(pStatus ==  CommandStatus::OK)
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "ERR" << std::endl;
		switch(pStatus)
		{
			case CommandStatus::GENERIC_ERROR:
				//printMessage("an error occured");
				break;
			case CommandStatus::BAD_COMMAND:
				printMessage("invalid command");
				break;
			case CommandStatus::BAD_PARAM_NB:
				printMessage("invalid parameters");
				break;
			default:
				break;
		}
	}
}

/**
 * Info de validité d'une commande. Contient les infos à faire vérifier par l'interpréteur.
 */
struct CommandInfo
{
	CommandInfo(int pParamNb) : ParamNb(pParamNb) {}
	int ParamNb;///<Nombre de paramètres acceptés par la commande. Si ce nombre n'est pas connu, mettre -1
};

/**
 * Rapport de l'interpréteur. Contient les informations données lors de l'interprétation de la commande.
 */
struct CommandFeedback
{
	CommandCode Code;///<Code de la commande
	std::deque<std::string> Args;///<Paramètres passés à la commande. Ne contient pas le nom de la commande
	CommandStatus Status;///<Statut de la commande
};

/**
 * Interpréteur de commandes. Cette classe est chargée d'effectuer les opérations de base sur la commande (existence et validité des paramètres)
 */
class Interpreter
{
	public:
		Interpreter();
		virtual ~Interpreter();

		/**
		 * Lit une ligne à la recherche d'une commande.
		 * \param line La ligne à interpréter. Attention, line est considérée comme non vide
		 * \return Un rapport sur la validité ou non de la commande
		 */
		CommandFeedback* Read(std::string line);
	
	private:
		CommandCode getCodeFromStr(std::string);

		std::map<std::string,CommandCode> commandName;
		std::map<CommandCode,CommandInfo*> commandInfos;
};

#endif
