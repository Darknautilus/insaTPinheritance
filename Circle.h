// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include <iostream>
#include <sstream>

#include "GeoElt.h"
#include "Point.h"

using std::string;

class Circle : public GeoElt
{
	public:
		Circle(int,int,int);
		virtual ~Circle();

		bool Move(int,int);
		string Display(string);
		string GetName()const;

	protected:
		int radius;
		Point center;
};

#endif
