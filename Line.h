#ifndef LINE_H
#define LINE_H

#include "GeoElt.h"
#include "Point.h"

class Line : public GeoElt
{
	public:
		Line(Point*,Point*);
		virtual ~Line();

		bool Move(int,int);

	protected:
		std::list<Point*> ends;

};

#endif
