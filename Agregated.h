// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef AO_H
#define AO_H

#include <map>

#include "GeoElt.h"

class Agregated : public GeoElt
{
	public:
		Agregated();
		virtual ~Agregated();

		bool Add(std::string, GeoElt*);
		bool Move(int,int);
		std::string Display(std::string);

	protected:
		std::map<std::string,GeoElt*> elements;
};

#endif
