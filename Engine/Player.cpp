#include "Player.h"

Player::Player(Location & loc, int ID)
{
	pos.loc = loc;
	pos.SetID(ID);
}

void Player::Update(Grid & grd, Keyboard& kbd)
{
	
	if (!HasMoved)
	{
		if (kbd.KeyIsPressed('A')) delta_pos = { -1,0 };
		if (kbd.KeyIsPressed('D')) delta_pos = { 1,0 };
		if (kbd.KeyIsPressed('W')) delta_pos = { 0,-1 };
		if (kbd.KeyIsPressed('S')) delta_pos = { 0,1 };
		const Location& next_pos = GetNextPos(delta_pos);
		if (grd.GetTile(next_pos).GetID() != 0 || !grd.IsInGrid(next_pos))
		{
			Move(Location{ 0,0 });
		}
		else
		{
			Move(delta_pos);
			delta_pos = { 0,0 };
			MoveCounter();
		}
	}
	else
	{
		if (CountMoved > 0)
		{
			--CountMoved;
		}
		else
		{
			HasMoved = false;
		}
	}
}

Location Player::GetNextPos(Location & delta_loc)
{
	Location Temp = pos.loc;
	Temp.Add(delta_loc);
	return Temp;
}

void Player::Move(Location & delta_loc)
{
	pos.loc.Add(delta_loc);
}

void Player::MoveCounter()
{
	HasMoved = true;
	CountMoved = 10;
}

void Player::Draw(Grid & grd) const
{
	grd.DrawCell(pos, c);
}
