// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef LINE_H
#define LINE_H

#include "GeoElt.h"

class Line : public GeoElt
{
	public:
		Line(Point*,Point*);
		virtual ~Line();

		bool Move(int,int,int);
		std::string Display(std::string);

	protected:
		std::list<Point*> ends;
};

#endif
