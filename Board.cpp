#include "Board.h"

#include <set>


Board::Board()
{
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++){
			_board[i][j] = new Tile(i, j, 0);
		}
	}
}


Board::~Board()
{
}


bool Board::put(int x, int y, int l){
	if (_board[x][y]->level != 0){
		return false;
	}
	else{
		while (updateBoard(x, y)){}

		return true;
	}
}

bool Board::updateBoard(int x, int y){

	// top down
	bool needUpdate = false;
	int l = _board[x][y]->level;

	std::set<Tile *> tileset;
	tileset.insert(_board[x][y]);

	fillTileSet(x, y, &tileset);


	if (tileset.size() == 1){
		return false;
	}

	std::set<Tile *>::iterator iter;
	std::set<Tile *> resSet;
	for (iter = tileset.begin(); iter != tileset.end(); ++iter) {
		Tile *cur = *iter;
		fillTileSet(cur->x, cur->y, &resSet);
	}

	if (resSet.size() > 3){
		for (iter = resSet.begin(); iter != resSet.end(); ++iter) {
			Tile *cur = *iter;
			cur->level = 0;
		}

		_board[x][y]->level = l + 1;
		return true;
	}

	return false;
}


void Board::fillTileSet(int x, int y, std::set<Tile *> * ts){
	std::set<Tile *> tileset = *ts;

	if (tileset.find(_board[x][y]) == tileset.end()){
		tileset.insert(_board[x][y]);
	}

	int l = _board[x][y]->level;

	if (x > 0){
		if (_board[x - 1][y]->level == l){
			if (tileset.find(_board[x - 1][y]) == tileset.end()){
				tileset.insert(_board[x - 1][y]);
			}
		}
	}

	if (x < 6){
		if (_board[x + 1][y]->level == l){
			if (tileset.find(_board[x + 1][y]) == tileset.end()){
				tileset.insert(_board[x + 1][y]);
			}
		}
	}
	if (y > 0){
		if (_board[x][y - 1]->level == l){
			if (tileset.find(_board[x][y - 1]) == tileset.end()){
				tileset.insert(_board[x][y - 1]);
			}
		}
	}

	if (y < 6){
		if (_board[x][y + 1]->level == l){
			if (tileset.find(_board[x][y + 1]) == tileset.end()){
					tileset.insert(_board[x][y + 1]);
				}
		}
	}

	return;
}
