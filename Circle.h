// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef CIRCLE_H
#define CIRCLE_H

#include "GeoElt.h"

class Circle : public GeoElt
{
	public:
		Circle(int,int,int);
		virtual ~Circle();

		bool Move(int,int,int);
		std::string Display(std::string);
		std::string GetName()const;

	protected:
		int radius;
		Point center;
};

#endif
