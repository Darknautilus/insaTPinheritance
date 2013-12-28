#ifndef GEOELT_H
#define GEOELT_H

#include <list>

class GeoElt
{
	public:
		GeoElt() {}
		virtual ~GeoElt() {}

		virtual bool Move(int,int) = 0;
};

#endif
