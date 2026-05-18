#ifndef MAP_H
#define MAP_H

#include "raylib.h"
#include "config.h"
#include <string> 

#define MAP_COLS (SCREEN_WIDTH / TILE_SIZE)
#define MAP_ROWS (SCREEN_HEIGHT / TILE_SIZE)

class GameMap {
private:
    int grid[MAP_ROWS][MAP_COLS];
    Texture2D wallSprite;

public:
    GameMap();
    ~GameMap();
    
    bool LoadMap(const std::string& filename); 
    bool IsSolid(int targetX, int targetY);
    bool CheckCollision(Rectangle rect);
    void Draw();
};

#endif