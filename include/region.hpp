#ifndef REGION_HPP_
#define REGION_HPP_

#include "tile.hpp"
#include "raylib.h"
#include <vector>
#include <any>

std::vector<std::any> serializeTiles(std::vector<Tile*> tiles);

std::vector<Tile> deserializeTiles(std::vector<std::any> serial);

#endif
