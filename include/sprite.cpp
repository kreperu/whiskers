#include "sprite.hpp"

void Sprite::addTexture(Texture2D* texture) {
	Tile::addTexture(texture);
	this->ax = this->x + this->width / 2;
	this->ay = this->y + this->height;
	return;
}

void Sprite::resize(int width, int height) {
	Tile::resize(width, height);
	this->ax = this->x + this->width / 2;
	this->ay = this->y + this->height;
}