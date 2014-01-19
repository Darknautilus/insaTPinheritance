// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <map>
#include <deque>
#include <fstream>
#include "GeoElt.h"

using std::string;

class Model
{
	typedef std::deque<GeoElt*>::iterator itElt;
	typedef std::map<std::string,int>::iterator itIndex;
	
	public:
		Model();
		virtual ~Model();

		bool Add(GeoElt*, std::string, bool = false);
		GeoElt* Delete(std::string, bool = false);
		GeoElt* Move(std::string, Point*);
		bool SaveInFile(std::string);
		void List();
		void Clear();

	protected:
		std::deque<GeoElt*> elements;
		std::deque<bool> deleted;
		std::map<std::string,int> eltIndexes;
};

#endif
