#include <iostream>
using namespace std;
#include "stdafx.h"
#ifndef TILE_H
#define TILE_H

class Tile
{
private:

	SDL_Rect r;

	bool solid;

public:
	Tile();
	Tile(int x, int y, int width, int height, bool wall);
	Tile(int size);
	void render(SDL_Renderer*, int i);
	SDL_Rect getRect();
	bool getSolid();


};

#endif

