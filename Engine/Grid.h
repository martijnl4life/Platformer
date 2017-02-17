#pragma once
#include "Location.h"
#include "Graphics.h"
#include "TileID.h"


class Grid
{
public:
	Grid(Graphics& gfx);
	void InitTiles();
	TileID GetTile(const Location& loc) const;
	void DrawCell(const TileID& tile, Color c) const;
	void DrawGrid() const;
private:
	static constexpr int cellDimension = 32;
	static constexpr int width = 10;
	static constexpr int height = 10;
	static constexpr int wallID = 1;
	int x = cellDimension;
	int y = cellDimension;
	TileID tile[width*height];
	Graphics& gfx;
};