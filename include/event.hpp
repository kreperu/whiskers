#ifndef EVENT_HPP_
#define EVENT_HPP_

#include "tile.hpp"
#include <vector>
#include <map>
#include <any>

class EventHandler {
	public:
		std::vector<Tile*> tiles;
		std::map<int, Tile*> tilesId;
		std::map<int, std::map<char*, std::any>> idPropertiesVal;
		std::map<int, std::vector<char*>> idPropertiesHas;
		std::map<std::vector<int>, Tile*> tilesXYZ;
		
		bool handleEvents(std::vector<Tile*>* tiles);
		int addToHandler(Tile* tile);
		Tile* getTileById(int id);
		Tile* getTileByXYZ(int x, int y, int z);
		// Return vectow of tiwes* with pwopewty (propName) == vawue (propVal)
		std::vector<Tile*> getTilesByPropVal(char* propName, std::any propVal);
		// Return vectow of tiwes* containing pwopewty (propName)
		std::vector<Tile*> getTilesByPropHas(char* propName);
};

#endif
