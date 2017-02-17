#include "Grid.h"

Grid::Grid(Graphics & gfx)
	:
	gfx(gfx)
{
	InitTiles();
}

void Grid::InitTiles()
{
	for (int i = 0; i < width * height; i++)
	{
		Location pos = { i % width, i / width };
		tile[i] = { 0,pos };
	}
	tile[0].SetID(wallID);
}

TileID Grid::GetTile(const Location & loc) const
{
	return tile[loc.y * width + loc.x];
}

bool Grid::IsInGrid(const Location & loc) const
{
	return loc.x >= 0 && loc.x < width && loc.y >= 0 && loc.y < height;
}

void Grid::DrawCell(const TileID & tile, Color c) const
{
	gfx.DrawRectDim(tile.loc.x * cellDimension + x, tile.loc.y * cellDimension + x, cellDimension, cellDimension, c);
}

void Grid::DrawGrid() const
{
	for (int i = 0; i < width * height; i++)
	{
		if (tile[i].ID == wallID)
		{
			DrawCell(tile[i], Colors::Gray);
		}
	}
}
