#include "event.hpp"

bool EventHandler::handleEvents(std::vector<Tile*>* tiles) {
	return false;
}

int EventHandler::addToHandler(Tile* tile) {
	this->tiles.push_back(tile);
	int id = this-> tilesId.size();
	this->tilesId[id] = tile;
	this->idPropertiesVal[id] = tile->prop;
	auto keyView = std::views::keys(tile->prop);
	std::vector<char*> keys{keyView.begin(), keyView.end()};
	this->idPropertiesHas[id] = keys;
	std::vector<int> xyz = {tile->x, tile->y, tile->z};
	this->tilesXYZ[xyz] = tile;
	return id;
}

bool EventHandler::removeFromHandler(int id) {
	std::vector<Tile*>::iterator curTilesSize = this->tiles.end();
	this->tiles.erase(this->tiles.begin() + id);
	std::vector<Tile*> subTiles{this->tiles.begin() + id, this->tiles.end() + 0};
	this->tiles.insert(this->tiles.begin() + id, subTiles.begin(), subTiles.end());
	this->tiles.erase(curTilesSize, this->tiles.end());
	return false;
}

Tile* EventHandler::getTileById(int id) {
	return this->tilesId[id];
}

Tile* EventHandler::getTileByXYZ(int x, int y, int z) {
	std::vector<int> xyz = {x, y, z};
	return this->tilesXYZ[xyz];
}
template<typename T>
std::vector<Tile*> EventHandler::getTilesByPropVal(char* propName, T propVal) {
	std::vector<Tile*> ret;
	for(auto&& [id, propMap] : this->idPropertiesVal) {
		if(std::any_cast<T>(propMap[propName]) == propVal) ret.push_back(getTileById(id));
	}
	return ret;
}

std::vector<Tile*> EventHandler::getTilesByPropHas(char* propName) {
	std::vector<Tile*> ret;
	for(auto&& [id, propMap] : this->idPropertiesVal) {
		if(propMap.count(propName)) ret.push_back(getTileById(id));
	}
	return ret;
}
