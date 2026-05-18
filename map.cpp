#include "map.h"
#include <fstream>
#include <iostream>

GameMap::GameMap() {
    // Fill with empty space by default
    for (int y = 0; y < MAP_ROWS; y++) {
        for (int x = 0; x < MAP_COLS; x++) {
            grid[y][x] = 0;
        }
    }

    // LOAD THE SPRITE: Sends the wall image to your graphics card
    wallSprite = LoadTexture("src/sprite/wall.png"); 
}

// THE DESTRUCTOR: Runs automatically when the map is destroyed
GameMap::~GameMap() {
    UnloadTexture(wallSprite); 
}

// MAP PARSER
bool GameMap::LoadMap(const std::string& filename) {
    // Open the file
    std::ifstream file(filename);

    // Safety Check: Did the file actually open?
    if (!file.is_open()) {
        std::cout << "ERROR: Could not load map file: " << filename << std::endl;
        return false;
    }

    // Read the numbers into the grid
    for (int y = 0; y < MAP_ROWS; y++) {
        for (int x = 0; x < MAP_COLS; x++) {
            file >> grid[y][x]; // The >> operator automatically skips spaces and newlines
        }
    }

    // Close the file (free up system memory)
    file.close();
    std::cout << "SUCCESS: Loaded map: " << filename << std::endl;
    return true;
}

bool GameMap::IsSolid(int targetX, int targetY) {
    // BOUNDS CHECK: Prevent the game from crashing if we check outside the screen
    if (targetX < 0 || targetX >= MAP_COLS || targetY < 0 || targetY >= MAP_ROWS) {
        return true; 
    }

    // TILE CHECK: Is the destination a wall?
    if (grid[targetY][targetX] == 1) {
        return true;
    }

    return false; // The space is safe to walk on
}

void GameMap::Draw() {
    for (int y = 0; y < MAP_ROWS; y++) {
        for (int x = 0; x < MAP_COLS; x++) {
            if (grid[y][x] == 1) {
                // WHITE means "draw the image with its original colors"
                DrawTexture(wallSprite, x * TILE_SIZE, y * TILE_SIZE, WHITE);
            }
        }
    }
}

// Convert the pixel boundaries of the bounding box into grid rows and columns
bool GameMap::CheckCollision(Rectangle rect) {
    int startCol = (int)(rect.x / TILE_SIZE);
    int endCol = (int)((rect.x + rect.width) / TILE_SIZE);
    int startRow = (int)(rect.y / TILE_SIZE);
    int endRow = (int)((rect.y + rect.height) / TILE_SIZE);

    // Scan only the specific subset of tiles the bounding box is currently touching
    for (int row = startRow; row <= endRow; row++) {
        for (int col = startCol; col <= endCol; col++) {
            if (IsSolid(col, row)) {
                return true; // At least one tile we are touching is solid
            }
        }
    }
    return false; // Free space
}