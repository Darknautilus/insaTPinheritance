// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "GeoElt.h"

class Rectangle : public GeoElt
{
	public:
		Rectangle(Point*,Point*);
		virtual ~Rectangle();

		bool Move(int,int);
		std::string Display(std::string);

	protected:
		Point* PtSupG;
		Point* PtInfD;
};

#endif
