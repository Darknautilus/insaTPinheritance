#ifndef GEOELT_H
#define GEOELT_H

#include <list>
#include <string>
<<<<<<< HEAD
=======

#include "Point.h"
>>>>>>> 4dc019fce05dd37a2608d06742f3fcac910c5618

class GeoElt
{
	public:
		GeoElt() {}
		virtual ~GeoElt() {}

		virtual bool Move(int,int) = 0;
		virtual std::string Display()=0;
};

#endif
