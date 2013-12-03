#pragma once
class Tile
{
public:
	Tile();
	~Tile();

	int getX();
	int getY();
	int getLevel();

	void setX();
	void setY();
	void setLevel();

private:
	int _x;
	int _y;
	int _level;

};

