#include "tile.hpp"
#include <cmath>

Tile::Tile(int x, int y) {
	this->x = x;
	this->y = y;
	this->width = 0;
	this->height = 0;
	this->hitbox[0] = x;
	this->hitbox[1] = y;
	this->hitbox[2] = x + this->width;
	this->hitbox[3] = y + this->height;
	return;
}

void Tile::addTexture(Texture2D* texture) {
	this->texture = *texture;
	return;
}

void Tile::addTextureFromFile(const char* filename) {
	this->texture = LoadTexture(filename);
	return;
}

void Tile::resize(int width, int height) {
	this->width = width;
	this->height = height;
	this->hitbox[2] = this->x + width;
	this->hitbox[3] = this->y + height;
	Image imgtxt = LoadImageFromTexture(this->texture);
	ImageResize(&imgtxt, width, height);
	this->texture = LoadTextureFromImage(imgtxt);
	return;
}

void Tile::move(int x, int y) {
	this->x = x;
	this->y = y;
	this->hitbox[0] = x;
	this->hitbox[1] = y;
	this->hitbox[2] = x + this->width;
	this->hitbox[3] = y + this->height;
	return;
}

bool Tile::inHitboxS(int* hitbox) {
	if(*(hitbox) >= this->hitbox[0] && *(hitbox+1) >= this->hitbox[1] && *(hitbox+2) <= this->hitbox[2] && *(hitbox+3) <= this->hitbox[3]) {
		return true;
	}
	return false;
}

void Tile::display() {
	DrawTexture(this->texture, this->x, this->y, WHITE);
	return;
}
