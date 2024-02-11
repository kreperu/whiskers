#ifndef TILE_HPP_
#define TILE_HPP_

#include "raylib.h"
#include <vector>
#include <map>
#include <any>

class Tile {
	public:
		int width;
		int height;
		Texture2D texture;
		int x;
		int y;
		int z;
		int hitbox[4];
		std::vector<void (*)(Tile*, std::any)> event;
		std::map<char*, std::any> prop;

		Tile();
		Tile(int x, int y, int z);
		// add tile texture from texture object
		void addTexture(Texture2D* texture);
		// add tile texture from filename
		void addTextureFromFile(const char* filename);
		// add property of std::any type
		void add(const char* propName, std::any propVal);
		// add event function pointer
		void add(void (*event)(Tile*, std::any));
		// resize tile
		void resize(int width, int height);
		// move tile to x, y
		void move(int x, int y, int z);
		void move(std::vector<int> xyz);
		// display tile
		void display();
		std::any getProp(const char* propName);
		std::any getProp(char* propName);
};

#endif
