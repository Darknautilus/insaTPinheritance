// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef GEOELT_H
#define GEOELT_H

#include <list>
#include <string>
#include <sstream>

#include "Point.h"

class GeoElt
{
	public:
		GeoElt() {}
		virtual ~GeoElt() {}

		virtual bool Move(int,int) = 0;
		virtual std::string Display(std::string)=0;
};

#endif
