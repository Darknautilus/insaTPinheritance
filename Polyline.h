#ifndef POLYLINE_H
#define POLYLINE_H

#include "GeoElt.h"
#include "Point.h"

class Polyline : public GeoElt
{
	public:
		Polyline();
		virtual ~Polyline();

		bool Add(Point*);
		bool Move(int,int);

	protected:
		std::list<Point*> points;
};

#endif
