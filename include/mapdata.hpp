#ifndef MAPDATA_HPP_
#define MAPDATA_HPP_

#include <map>
#include <any>

template<typename T>
char* serializeMap(std::map<T, T> data) {
	char* serial = "";
	for(auto&& [key, val] : data) {
		serial = *serial + *(char*)key;
		serial = *serial + ": ";
		serial = *serial + *(char*)val;
		serial = *serial + ";\n";
	}
	return serial;
}

#endif
