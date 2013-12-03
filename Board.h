#pragma once

#include <set>


struct Tile {
	Tile(int x, int y, int l) :
		x(x), y(y), level(l){
	}
	
	int x;
	int y;
	int level;
};


class Board
{
public:
	Board();
	~Board();

	bool put(int x, int y, int l);
	
	
private:
	bool updateBoard(int x, int y);
	Tile* _board[5][5];
	void fillTileSet(int x, int y, std::set<Tile *> * tileset);
};

