#ifndef EVENT_HPP_
#define EVENT_HPP_

#include "tile.hpp"
#include <vector>
#include <map>
#include <any>
#include <ranges>

class EventHandler {
	public:
		// Vector of all Tile* in EventHandler
		std::vector<Tile*> tiles;
		// Map of Tile id -> Tile with id
		std::map<int, Tile*> tilesId;
		// Map of Tile id -> map<propName -> propVal>
		std::map<int, std::map<char*, std::any>> idPropertiesVal;
		// Map of Tile id -> propName
		std::map<int, std::vector<char*>> idPropertiesHas;
		// Map of vector<x, y, z> -> Tile on x, y, z
		std::map<std::vector<int>, Tile*> tilesXYZ;
		
		// Handle all events
		bool handleEvents(std::vector<Tile*>* tiles);
		// Add tile to handler, return its id
		int addToHandler(Tile* tile);
		// Return Tile with the id id
		Tile* getTileById(int id);
		// Return Tile on position x, y, z
		Tile* getTileByXYZ(int x, int y, int z);
		// Return vectow of tiwes (Tile*) with pwopewty (propName) == vawue (propVal)
		std::vector<Tile*> getTilesByPropVal(char* propName, std::any propVal);
		// Return vectow of tiwes (Tile*) containing pwopewty (propName)
		std::vector<Tile*> getTilesByPropHas(char* propName);
};

#endif
