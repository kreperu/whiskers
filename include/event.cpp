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
