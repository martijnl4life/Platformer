#pragma once
#include "TileID.h"
#include "Location.h"
#include "Grid.h"
#include "Keyboard.h"


class Player
{
public:
	Player(Location& loc, int ID);
	void Update(Grid& grd, Keyboard& kbd);
	Location GetNextPos(Location& delta_loc);
	void Move(Location& delta_loc);
	void MoveCounter();
	void Draw(Grid& grd) const;
private:
	static constexpr Color c = Colors::Cyan;
	bool HasMoved;
	int CountMoved = 0;
	TileID pos;
	Location delta_pos = { 0,0 };
};