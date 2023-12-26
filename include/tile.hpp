#ifndef TILE_HPP_
#define TILE_HPP_

#include "raylib.h"

class Tile {
	public:
		int width;
		int height;
		Texture2D texture;
		int x;
		int y;
		int hitbox[4];

		Tile();
		Tile(int x, int y);
		// add tile texture from texture object
		void addTexture(Texture2D* texture);
		// add tile texture from filename
		void addTextureFromFile(const char* filename);
		// resize tile
		void resize(int width, int height);
		// move tile to x, y
		void move(int x, int y);
		// return wether hitbox is in obj.hitbox
		bool inHitboxS(int* hitbox);
		// display tile
		void display();
};

#endif
