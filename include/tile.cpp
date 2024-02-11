#include "tile.hpp"
#include <cmath>

Tile::Tile() {
	return;
}

Tile::Tile(int x, int y, int z) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->width = 0;
	this->height = 0;
	return;
}

void Tile::addTexture(Texture2D* texture) {
	this->texture = *texture;
	this->width = texture->width;
	this->height = texture->height;
	return;
}

void Tile::addTextureFromFile(const char* filename) {
	this->texture = LoadTexture(filename);
	this->width = this->texture.width;
	this->height = this->texture.height;
	return;
}

void Tile::add(const char* propName, std::any propVal) {
	this->prop[(char*)propName] = propVal;
	return;
}

void Tile::add(void (*event)(Tile*, std::any)) {
	this->event.push_back(event);
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

void Tile::move(int x, int y, int z) {
	this->x = x;
	this->y = y;
	this->z = z;
	return;
}

void Tile::move(std::vector<int> xyz) {
	this->x = xyz[0];
	this->z = xyz[1];
	this->y = xyz[2];
	return;
}

void Tile::display() {
	DrawTexture(this->texture, this->x, this->y, WHITE);
	return;
}

std::any Tile::getProp(const char* propName) {
	std::any prop = this->prop[(char*)propName];
	return prop;
}

std::any Tile::getProp(char* propName) {
	return this->prop[propName];
}
