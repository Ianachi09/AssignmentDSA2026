all:
	g++ assignment.cpp -o assignment -I/c/raylib/raylib/include -L/c/raylib/raylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm -static-libgcc -static-libstdc++