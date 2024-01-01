#ifndef EVENT_HPP_
#define EVENT_HPP_

#include "tile.hpp"
#include <vector>
#include <map>
#include <any>
#include <ranges>

class EventHandler {
	public:
		Vector2 empty;
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
		
		// Queue for drawing
		std::map<void (*)(Tile*), Tile*> drawQueue;

		// Handle all events
		void handleEvents();
		// Handle add drawing requests
		void handleDrawing();
		// Add tile to handler, return its id
		int addToHandler(Tile* tile);
		// Remove Tile of id from handler
		bool removeFromHandler(int id);
		// Return Tile with the id id
		Tile* getTileById(int id);
		// Return Tile on position x, y, z
		Tile* getTileByXYZ(int x, int y, int z);
		// Return vectow of tiwes (Tile*) with pwopewty (propName) == vawue (propVal)
		template<typename T>
		std::vector<Tile*> getTilesByPropVal(char* propName, T propVal);
		// Return vectow of tiwes (Tile*) containing pwopewty (propName)
		std::vector<Tile*> getTilesByPropHas(char* propName);

		int getIdByTile(Tile* tile);
		
		// Add function to drawQueue
		EventHandler* draw(void (*func)(Tile*), Tile* tile);
};

#endif
