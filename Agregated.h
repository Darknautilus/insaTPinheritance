// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef AO_H
#define AO_H

#include "GeoElt.h"

struct AgregatedElement
{
	GeoElt *element;
	int index;
};

class Agregated : public GeoElt
{
	public:
		Agregated();
		virtual ~Agregated();

		bool Add(std::string, GeoElt*);
		bool Delete(std::string);

		bool Move(int,int);
		std::string Display(std::string);

	protected:
		std::map<std::string,AgregatedElement> elements;
};

#endif
