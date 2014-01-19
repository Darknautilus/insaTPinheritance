// =====
// INSA Lyon, Département Informatique
// TP C++ 3IF :  Héritage et polymorphisme
// Auteur : B3229
// =====

#ifndef POLYLINE_H
#define POLYLINE_H

#include "GeoElt.h"
#include "Point.h"
#include <string>
using namespace std;

class Polyline : public GeoElt
{
	public:
		Polyline();
		virtual ~Polyline();

		bool Add(Point*);
		bool Move(int,int);
		string Display(string);
		string GetName() const;
		
	protected:
		list<Point*> points;
};

#endif
