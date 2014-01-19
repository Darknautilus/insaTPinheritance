// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef AO_H
#define AO_H

#include "GeoElt.h"
#include <string>
#include <map>
using namespace std;

class AO : public GeoElt
{
	public:
		AO();
		virtual ~AO();

		bool Add(string, GeoElt*);
		bool Move(int,int);
		string Display(string);

	protected:
		std::map<string,GeoElt*> elements;
};

#endif
