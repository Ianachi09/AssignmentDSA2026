#include <iostream>
#include "raylib.h"
Color turqoise={0,255,255,255};
Color darkred={67,0,0,255};

int cellSize=30;
int cellCount=25;
Vector2 GenerateRandomPos();

class Snake{
	
};

class Food{
	public:
		Food();
		~Food();
		Texture2D texture;
		Vector2 position;
		void Draw();

	private:

};

Food::Food(){
	Image image=LoadImage("Graphics/Food.png");
	texture=LoadTextureFromImage(image);
	position = GenerateRandomPos();
	UnloadImage(image);
}
Food::~Food(){
	UnloadTexture(texture);
}
void Food::Draw(){
	DrawTexture(texture,position.x*(10+cellSize),position.y*(10+cellSize),WHITE);
}
Vector2 GenerateRandomPos(){
	float x = GetRandomValue(0,cellCount-1);
	float y = GetRandomValue(0, cellCount-1);
	return Vector2{x,y};
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

