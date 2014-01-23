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

		bool Add(GeoElt*, std::string, bool = false);
		GeoElt* Delete(std::string, bool = false);
		GeoElt* Move(std::string, Point*);
		bool SaveInFile(std::string);
		void List();
		void Clear();
		/**
		 * Vérifie que le nom donné existe. Vérifie dans le modèle que l'élément spécifié par son nom existe.
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
