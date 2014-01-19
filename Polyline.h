// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef POLYLINE_H
#define POLYLINE_H

#include "GeoElt.h"

class Polyline : public GeoElt
{
	public:
		Polyline();
		virtual ~Polyline();

		bool Add(Point*);
		bool Move(int,int);
		std::string Display(std::string);
		
	protected:
		std::list<Point*> points;
};

#endif
