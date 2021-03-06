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
	bool deleted;
};

class Agregated : public GeoElt
{
	public:
		Agregated();
		virtual ~Agregated();

		bool Add(std::string, GeoElt*);
		bool Delete(std::string);
		bool SetDeleted(std::string,bool);

		bool Move(int,int,int);
		std::string Display(std::string);

	protected:
		std::map<std::string,AgregatedElement> elements;
};

#endif
