#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <map>

#include "GeoElt.h"

class Model
{
	using namespace std;
	
	public:
		Model();
		virtual ~Model();

		bool Add(GeoElt*, string);
		bool Delete(string);
		bool Move(string, Point&);
		bool SaveInFile(string);

	protected:
		std::list<GeoElt*> elements;
		std::map<string,int> eltIndexes;
};

#endif
