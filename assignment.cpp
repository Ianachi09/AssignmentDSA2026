#include <iostream>
#include "raylib.h"
Color turqoise={0,255,255,255};
Color darkred={67,0,0,255};

int cellSize=30;
int cellCount=25;

class Food{
	public:
		Food();
		~Food();
		Vector2 position={5,6};
		Texture2D texture;
		void Draw();

	private:

};

Food::Food(){
	Image image=LoadImage("Graphics/Food.png");
	texture=LoadTextureFromImage(image);
	UnloadImage(image);
}
Food::~Food(){
	UnloadTexture(texture);
}
void Food::Draw(){
	DrawTexture(texture,position.x*(10+cellSize),position.y*(10+cellSize),WHITE);
}
int main() {
	std::cout<<"Starting Game";
	InitWindow(cellSize*cellCount,cellSize*cellCount, "Snake Game");
	Food food;
	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		BeginDrawing();
		food.Draw();
		ClearBackground(darkred);
		DrawText("WIP", 190, 200, 20, turqoise);

		EndDrawing();
	}
	CloseWindow();
	return 0;
}

