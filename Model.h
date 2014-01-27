// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <fstream>
#include <deque>

#include "Executor.h"

struct ElementMarker
{
	GeoElt* element;
	bool deleted;
};

class Model
{
	typedef std::map<std::string,ElementMarker>::iterator eltIt;
	
	public:
		Model();
		virtual ~Model();

		/**
		 * Ajoute un élément au modèle. Deux modes d'ajout sont disponibles : ajout simple ou forcé. L'ajout simple est utilisé si l'on n'insère pas de nouvel élément dans le modèle (lors du Undo d'une command DELETE, par exemple). L'ajout forcé est utilisé lors d'une commande ADD.
		 * \param element L'élément à ajouter
		 * \param name Le nom à donner à l'élément
		 * \param force Forcer l'ajout ou non
		 * \return true si l'ajout s'est bien déroulé et false sinon
		 * \sa Controller::Add()
		 */
		bool Add(GeoElt *element, std::string name, bool force = false);
		/**
		 * Supprime un élément du modèle. Comme dans Model::Add(), deux modes de suppression sont disponibles : simple ou forcé. La suppression simple est utilisée dans la plupart des cas, et marque l'élément comme supprimé (cf. ElementMarker) mais ne le retire pas à proprement parler du modèle. La suppression forcée est utilisée principalement dans le destructeur de AddCommand.
		 * \param name Le nom de l'élément à supprimer
		 * \param force Forcer la suppression ou non
		 * \return Un pointeur vers l'élément supprimé si tout s'est bien passé et 0 sinon
		 * \sa Controller::Delete()
		 */
		GeoElt* Delete(std::string name, bool force = false);
		/**
		 * Déplace un élément.
		 * \param name Le nom de l'élément à déplacer
		 * \param direction Le vecteur de déplacement
		 * \param commandId L'id de la commande qui a appelé la méthode. Cf. GeoElt::Move()
		 * \return Un pointeur vers l'élément déplacé si tout s'est bien passé et 0 sinon
		 * \sa Controller::Move(), GeoElt::Move()
		 */
		GeoElt* Move(std::string name, Point *direction, int commandId);
		/**
		 * Sauvegarde le contenu du modèle dans un fichier. Cette méthode appelle simplement la méthode Display() sur tous les éléments du modèle.
		 * \param filename
		 * \return true si tout s'est bien déroulé et false sinon
		 * \sa GeoElt::Display()
		 */
		bool SaveInFile(std::string filename);
		void List();
		void Clear();
		/**
		 * Vérifie que l'élément donné existe. Vérifie dans le modèle que l'élément spécifié par son nom existe.
		 * Attention, même si l'élément est dans le modèle, la fonction retournera faux si l'élément a été marque comme supprimé. Cela peut mener à des contradictions lors d'un Add par exemple : si l'élément est marqué comme supprimé, alors Exists() renverra bien faux mais Add échouera.
		 *
		 * \param name Le nom de l'élément
		 * \return Un pointeur vers l'élément s'il existe et 0 sinon.
		 * \sa Model::Exists()
		 */
		GeoElt *Exists(std::string name);

	protected:
		std::map<std::string,ElementMarker> elements;
};

#endif
