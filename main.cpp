#include <stdio.h>
#include "raylib.h"

#include "tile.hpp"
#include "event.hpp"

int main() {
	InitWindow(800, 400, "test");
	SetWindowMaxSize(GetScreenWidth(), GetScreenHeight());
	SetTargetFPS(144);
	
	Texture2D cat = LoadTexture("assets/cat.png");
	Tile* sp = new Tile(0, 0, 0);
	sp->addTexture(&cat);
	sp->resize(64, 128);

	int xPos = -cat.width;

	while(!WindowShouldClose()) {
		
		if(IsKeyPressed(KEY_F11)) {
			ToggleFullscreen();
		}
		
		if(xPos > GetScreenWidth()) xPos = -cat.width-1;
		sp->move(xPos, 0);

		BeginDrawing();

		ClearBackground(RAYWHITE);
		sp->display();

		EndDrawing();

		xPos += 1;
	}

	CloseWindow();

	return 0;
}
