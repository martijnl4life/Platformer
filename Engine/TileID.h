#pragma once
#include "Location.h"



class TileID
{
public:
	void SetID(int in_ID)
	{
		ID = in_ID;
	}
	int GetID() const
	{
		return ID;
	}
public:
	int ID;
	Location loc;
};







