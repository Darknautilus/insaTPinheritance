#ifndef CIRCLE_H
#define CIRCLE_H

#include "GeoElt.h"
#include "Point.h"

class Circle : public GeoElt
{
	public:
		Circle(int,int,int);
		virtual ~Circle();

		bool Move(int,int);

	protected:
		int radius;
		Point center;
};

#endif
