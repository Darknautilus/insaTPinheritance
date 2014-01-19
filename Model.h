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

	protected:
		std::map<std::string,ElementMarker> elements;
	
	friend bool Executor::Execute(CommandFeedback*,FileCommand*);
};

#endif
