#ifndef COMPONENTS_HPP_
#define COMPONENTS_HPP_

#include "tile.hpp"
#include "event.hpp"
#include "isometric.hpp"
#include <cmath>
#include "region.hpp"
#include <vector>
#include <set>

void drawSelf(Tile* that, std::any e);
void moveSelf(Tile* that, std::any e);

void playerMovableComponent(Tile* that, std::any e) {
	moveSelf(that, e);
	drawSelf(that, e);
}

//add Tile* that to drawing queue of EventHandler in std::any e
void drawSelf(Tile* that, std::any e) {
	EventHandler* event = std::any_cast<EventHandler*>(e);
	event->draw([](Tile* tile){
		tile->display();
		return;
	}, that);
	return;
}

void collideSelf(Tile* that, std::any e) {
	EventHandler* event = std::any_cast<EventHandler*>(e);
	std::vector<Tile*> tiles = event->tiles;
	std::vector<float> thatxyz = std::any_cast<float>(that->getProp("worldPosXYZ"));
	for(auto& tile : tiles) {
		std::vector<float> tilexyz = std::any_cast<float>(tile->getProp("worldPosXYZ"));
		if(tilexyz[0]+ = thatxyz[1])
	}
	
}

//make Tile* that movable - add moving event to event queue of EventHandler in std::any e
void moveSelf(Tile* that, std::any e) {

	/*       y
	 *	 |
	 *	 |
	 *	 |
	 *	 |_________x
	 *      /
	 *     /
	 *    /
	 *   z
	*/

	//calculate xz movement
	float vZ = IsKeyDown(KEY_W) ? -20 * GetFrameTime() : IsKeyDown(KEY_S) ? 20 * GetFrameTime() : 0;
	float vX = IsKeyDown(KEY_A) ? -20 * GetFrameTime() : IsKeyDown(KEY_D) ? 20 * GetFrameTime() : 0;
	
	//calculate y movement - jump
	that->prop[(char*)"jumpVelocity"] = IsKeyPressed(KEY_SPACE) && std::ceil(std::any_cast<float>(that->prop[(char*)"jumpVelocity"])) == 0 ? std::make_any<float>(2.0F) : /*std::make_any<float>(std::cos(std::any_cast<float>(that->getProp("jumpVelocity")) * M_PI / 10 + M_PI / 2));*/std::make_any<float>(std::any_cast<float>(that->getProp("jumpVelocity")) > 0 ? std::any_cast<float>(that->getProp("jumpVelocity")) - 0.03 : 0.0F);
	float vY = std::sin(std::any_cast<float>(that->getProp("jumpVelocity")) * M_PI) * -0.3;
	//vY = vY < -0.8 ? vY+0.5 : vY;
	//calculate new xyz pos and convert to isometric
	Tile copy;
	copy = *that;
	int width = copy.width;
	int height = copy.height;
	int cx = copy.x;
	int cz = copy.y;
	std::vector<float> worldXYZ = std::any_cast<std::vector<float>>(that->prop[(char*)"worldPosXYZ"]);
	std::vector<float> realXYZ{worldXYZ[0]+vX, worldXYZ[1]+vY, worldXYZ[2]+vZ};
	that->prop[(char*)"worldPosXYZ"] = realXYZ;
	std::vector<int> xyz = worldToIzoGrid(realXYZ[0], realXYZ[2], realXYZ[1], , height);
	
	/*
	std::vector<int> copyXYZ = xyz;
	int xLen = 1024 - copyXYZ[0];
	int yLen = 600 - copyXYZ[2];
	int smallestLen = xLen < yLen ? xLen : yLen;
	int maxSmallestLen = xLen < yLen ? 1024 : 600;
	for(int i = 0; i < maxSmallestLen-smallestLen; i++) {
	}
	//float moveVector = std::sqrt(std::pow(std::sqrt(xyz[0]*xyz[0]+xyz[1]*xyz[1]),2)+xyz[2]*xyz[2]);
	*/

	that->prop[(char*)"toMove"] = std::make_any<std::vector<int>>(xyz);
	that->move(std::any_cast<std::vector<int>>(that->prop[(char*)"toMove"]));
	EventHandler* event = std::any_cast<EventHandler*>(e);
	std::vector<int> vecXYZ{copy.x, copy.y, copy.z};
	std::vector<int> newVecXYZ = std::any_cast<std::vector<int>>(that->prop[(char*)"toMove"]);
	event->tilesXYZ.erase(vecXYZ);
	event->tilesXYZ.emplace(std::make_pair(newVecXYZ, that));
	return;
}

#endif
