#ifndef MODEL_H
#define MODEL_H

#include <map>
#include <vector>
#include <fstream>

#include "GeoElt.h"

using std::string;

class Model
{
	typedef std::vector<GeoElt*>::iterator itElt;
	typedef std::map<std::string,int>::iterator itIndex;
	
	public:
		Model();
		virtual ~Model();

		bool Add(GeoElt*, std::string);
		bool Delete(std::string);
		bool Move(std::string, Point*);
		bool SaveInFile(std::string);

	protected:
		std::vector<GeoElt*> elements;
		std::map<std::string,int> eltIndexes;
};

#endif
