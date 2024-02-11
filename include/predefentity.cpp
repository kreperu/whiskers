#include "tile.hpp"
#include "components.hpp"
#include "isometric.hpp"

Tile spawnMovablePlayer(int x, int y, int z) {
	Tile tile = Tile(0, 0, 0);
	tile.addTextureFromFile("assets/izocube.png");
	tile.add(&playerMovableComponent);

	std::vector<int> zeroInt{0, 0, 0};
	tile.add("toMove", std::make_any<std::vector<int>>(zeroInt));
	std::vector<float> zeroFloat{(float) x, (float) y, (float) z};
	tile.add("worldPosXYZ", std::make_any<std::vector<float>>(zeroFloat));
	tile.add("jumpVelocity", std::make_any<float>(0.0F));
	return tile;
}

/*
Tile* spawnBreakableTile(int x, int y, int y) {
	Tile tile = Tile(x, z, y);
}
*/
