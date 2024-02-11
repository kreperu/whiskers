#include "region.hpp"

std::vector<std::any> serializeTiles(std::vector<Tile*> tiles) {
	std::vector<int> ret;
	for(auto& tile : tiles) {
		ret.push_back(std::make_any<int>(tile->width));
		ret.push_back(std::make_any<int>(tile->height));
		ret.push_back(std::make_any<Texture2D>(tile->texture));
		ret.push_back(std::make_any<int>(tile->x));
		ret.push_back(std::make_any<int>(tile->y));
		ret.push_back(std::make_any<int>(tile->z));
		// End Of Frame (end basic, start events)
		ret.push_back(std::make_any<const char*>("EOF"));
		std::vector<void (*)(Tile*, std::any)> events = tile->event;
		for(auto& event : events) {
			ret.push_back(std::make_any<void (*)(Tile*, std::any)>(event));
		}
		// End Of Frame (end events, start props)
		ret.push_back(std::make_any<const char*>("EOF"));
		std::map<char*, std::any> props = tile->prop;
		for(auto& [key, prop] : props) {
			ret.push_back(std::make_any<char*>(key));
			ret.push_back(prop);
		}
		// End Of Object (end tile)
		ret.push_back(std::make_any<const char*>("EOO"));
	}
}

std::vector<Tile> deserializeTiles(std::vector<std::any> serial) {
	
}
