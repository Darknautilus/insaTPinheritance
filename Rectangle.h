// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polyline.h"
#include <string>
using namespace std;

class Rectangle : public GeoElt
{
	public:
		Rectangle(Point*,Point*);
		virtual ~Rectangle();

		bool Move(int,int);
		string Display(string);
		string GetName() const;

	protected:
		Point* PtSupG;
		Point* PtInfD;
};

#endif
