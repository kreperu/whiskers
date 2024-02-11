#ifndef ISOMETRIC_HPP_
#define ISOMETRIC_HPP_

#include "raylib.h"
//#include <ifstream.h>
#include <vector>
#include "tile.hpp"

std::vector<int> worldToIzoGrid(float x, float z, float y, int width, int height);

#endif
