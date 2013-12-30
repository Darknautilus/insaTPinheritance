#ifndef MODEL_H
#define MODEL_H

#include <map>

#include "GeoElt.h"

class Model
{
	public:
		Model();
		virtual ~Model();

		bool Add(GeoElt*, std::string);
		bool Delete(std::string);
		bool Move(std::string, Point*);
		bool SaveInFile(std::string);

	protected:
		std::list<GeoElt*> elements;
		std::map<std::string,int> eltIndexes;
};

#endif
