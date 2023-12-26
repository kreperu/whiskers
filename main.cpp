#include <stdio.h>
#include "raylib.h"

#include "tile.hpp"

int main() {
	InitWindow(800, 400, "test");
	SetWindowMaxSize(GetScreenWidth(), GetScreenHeight());
	SetTargetFPS(144);
	
	Texture2D cat = LoadTexture("assets/cat.png");
	Tile bg(0, 0);
	bg.addTextureFromFile("assets/nay.png");
	bg.resize(64, 64);

	int xPos = -cat.width;

	while(!WindowShouldClose()) {
		
		if(IsKeyPressed(KEY_F11)) {
			ToggleFullscreen();
		}
		
		if(xPos > GetScreenWidth()) xPos = -cat.width-1;

		BeginDrawing();

		ClearBackground(RAYWHITE);
		DrawTexture(cat, xPos, 10, WHITE);
		bg.display();

		EndDrawing();

		xPos += 10;
	}

	CloseWindow();

	return 0;
}
