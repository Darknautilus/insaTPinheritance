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
