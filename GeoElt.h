#ifndef GEOELT_H
#define GEOELT_H

#include <list>
#include <string>

#include "Point.h"

class GeoElt
{
	public:
		GeoElt() {}
		virtual ~GeoElt() {}

		virtual bool Move(int,int) = 0;
		virtual std::string Display()=0;
};

#endif
