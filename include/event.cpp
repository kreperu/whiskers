#include "event.hpp"

void EventHandler::handleEvents() {
	for(auto& tile : this->tiles) {
		for(auto& func : tile->event) {
			func(tile, std::make_any<EventHandler*>(this));
		}
	}
	return;
}

void EventHandler::handleDrawing() {
	for(auto& draw : drawQueue) {
		std::get<0>(draw)(std::get<1>(draw));
	}
	drawQueue.clear();
	return;
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
	if(id >= this->tiles.size()) return false;

	Tile* beforeRemove = getTileById(id-1);
	std::vector<int> backXYZ;
	if(id >= 1) backXYZ = {beforeRemove->x, beforeRemove->y, beforeRemove->z};
	Tile* afterRemove = getTileById(id+1);
	std::vector<int> frontXYZ;
	if((id + 1) < this->tiles.size()) frontXYZ = {afterRemove->x, afterRemove->y, afterRemove->z};

	std::vector<Tile*> backTiles{this->tiles.begin(), this->tiles.end()-(this->tiles.size()-id-1)}; if(id == 0) backTiles.clear();
	std::vector<Tile*> frontTiles{this->tiles.begin()+id+1, this->tiles.end()};
	backTiles.insert(backTiles.end(), frontTiles.begin(), frontTiles.end());
	this->tiles.clear();
	this->tiles.insert(this->tiles.begin(), backTiles.begin(), backTiles.end());
	

	std::map<int, Tile*> backTilesId{this->tilesId.begin(), this->tilesId.find(id-1)}; if(id == 0) backTilesId.clear();
	std::map<int, Tile*> frontTilesId{this->tilesId.find(id+1), this->tilesId.end()};
	backTilesId.insert(frontTilesId.begin(), frontTilesId.end());
	this->tilesId.clear();
	this->tilesId.insert(backTilesId.begin(), backTilesId.end());
	

	std::map<int, std::map<char*, std::any>> backIdPropertiesVal{this->idPropertiesVal.begin(), this->idPropertiesVal.find(id-1)}; if(id == 0) backIdPropertiesVal.clear();
	std::map<int, std::map<char*, std::any>> frontIdPropertiesVal{this->idPropertiesVal.find(id+1), this->idPropertiesVal.end()};
	backIdPropertiesVal.insert(frontIdPropertiesVal.begin(), frontIdPropertiesVal.end());
	this->idPropertiesVal.clear();
	this->idPropertiesVal.insert(backIdPropertiesVal.begin(), backIdPropertiesVal.end());


	std::map<int, std::vector<char*>> backIdPropertiesHas{this->idPropertiesHas.begin(), this->idPropertiesHas.find(id-1)}; if(id == 0) backIdPropertiesHas.clear();
	std::map<int, std::vector<char*>> frontIdPropertiesHas{this->idPropertiesHas.find(id+1), this->idPropertiesHas.end()};
	backIdPropertiesHas.insert(frontIdPropertiesHas.begin(), frontIdPropertiesHas.end());
	this->idPropertiesHas.clear();
	this->idPropertiesHas.insert(backIdPropertiesHas.begin(), backIdPropertiesHas.end());

	// id-1
	std::map<std::vector<int>, Tile*> backTilesXYZ{this->tilesXYZ.begin(), this->tilesXYZ.find(backXYZ)}; if(id == 0) backTilesXYZ.clear();
	std::map<std::vector<int>, Tile*> frontTilesXYZ{this->tilesXYZ.find(frontXYZ), this->tilesXYZ.end()};
	backTilesXYZ.insert(frontTilesXYZ.begin(), frontTilesXYZ.end());
	this->tilesXYZ.clear();
	this->tilesXYZ.insert(backTilesXYZ.begin(), backTilesXYZ.end());	

	return true;
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

int EventHandler::getIdByTile(Tile* tile) {
	for(auto&& [id, val] : this->tilesId) {
		if(tile == val) {
			return id;
		}
	}
	return -1;
}

EventHandler* EventHandler::draw(void (*func)(Tile*), Tile* tile) {
	this->drawQueue.push_back(std::make_pair(func, tile));
	return this;
}
