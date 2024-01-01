#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <any>
#include "raylib.h"

#include "tile.hpp"
#include "event.hpp"

void FPSEvent(Tile* that, std::any e) {
	EventHandler* event = std::any_cast<EventHandler*>(e);
	event->draw([](Tile*){DrawFPS(0, 0); DrawText(std::to_string(GetFrameTime()).c_str(), 0, 20, 20, DARKGREEN); return;}, that);
}

int main() {
	InitWindow(1024, 600, "TEST");
	SetWindowMaxSize(GetScreenWidth(), GetScreenHeight());
	SetTargetFPS(144);
	
	Texture2D cat = LoadTexture("assets/cat.png");
	Tile* FPSDisplay = new Tile(0, 0, 0);
	FPSDisplay->add(&FPSEvent);

	EventHandler* ev = new EventHandler();
	int FPSDisplayId = ev->addToHandler(FPSDisplay);
	

	while(!WindowShouldClose()) {
		ev->handleEvents();
		
		if(IsKeyPressed(KEY_F11)) {
			ToggleFullscreen();
		}

		BeginDrawing();

		ClearBackground(RAYWHITE);
		ev->handleDrawing();

		EndDrawing();

	}

	CloseWindow();

	return 0;
}
