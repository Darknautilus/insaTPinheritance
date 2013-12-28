#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polyline.h"

class Rectangle : public GeoElt
{
	public:
		Rectangle(Point*,Point*);
		virtual ~Rectangle();

		bool Move(int,int);

	protected:
		Polyline edge;
};

#endif
