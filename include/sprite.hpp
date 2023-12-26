#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include "raylib.h"
#include "tile.hpp"

class Sprite : public Tile {
	public:
		int ax;
		int ay;

		Sprite(int x, int y);
}

#endif
