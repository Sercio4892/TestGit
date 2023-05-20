#include "Grid.h"

Grid::Grid(Graphics& in_gfx,
	int in_width, int in_height,
	int in_bDimension, Location in_loc,
	int in_cWidth, int in_cHeight, int in_cborderDimension)
	:
	border(in_gfx, in_width*in_cWidth + 2*(in_bDimension + 0), in_height*in_cHeight + 2*(in_bDimension + 0), in_bDimension, in_loc),
	cell(in_gfx, in_cWidth, in_cHeight, in_cborderDimension, { in_loc.x + in_bDimension + 0, in_loc.y + in_bDimension + 0 })
			
{
	width = in_width;
	height = in_height;
}

Grid::Border::Border(Graphics& in_gfx, int in_width, int in_height, int in_dimension, Location in_loc)
	:
	gfx(in_gfx)
{
	width = in_width;
	height = in_height;
	dimension = in_dimension;

	pixLoc0 = in_loc;
}

Grid::Cell::Cell(Graphics& in_gfx, int in_width, int in_height, int in_borderDimension, Location in_loc0)
	:
	gfx (in_gfx)
{
	width = in_width;
	height = in_height;

	borderDimension = in_borderDimension;

	loc0 = in_loc0;
}



void Grid::DrawBorder(Color c)
{
	border.Draw(c);
}

void Grid::DrawCell(Location loc, Color cCol, Color cBorder)
{
	cell.Draw(loc, cCol, cBorder);
}

void Grid::Border::Draw(Color c)
{
	int x1 = pixLoc0.x;
	int y1 = pixLoc0.y;

	int x2 = x1 + width;
	int y2 = y1 + height;

	/* ********** HORIZONTAL LINES **********/
	for (int j = y1; j < y1 + dimension; ++j)
	{
		for (int i = x1; i < x2; ++i)
		{
			gfx.PutPixel(i, j, c);
		}
	}
	
	for (int j = y2 - dimension; j < y2; ++j)
	{
		for (int i = x1; i < x2; ++i)
		{
			gfx.PutPixel(i, j, c);
		}
	}
	/***************************************/


	/*********** VERTICAL LINES ************/
	for (int j = y1 + dimension; j < y2 - dimension; ++j)
	{
		for (int i = x1; i < x1 + dimension; ++i)
		{
			gfx.PutPixel(i, j, c);
		}
	}
	
	for (int j = y1 + dimension; j < y2 - dimension; ++j)
	{
		for (int i = x2 - dimension; i < x2; ++i)
		{
			gfx.PutPixel(i, j, c);
		}
	}
	/***************************************/

}

void Grid::Cell::Draw(Location loc, Color c, Color cBorder)
{
	int x1 = loc0.x + loc.x * width;
	int y1 = loc0.y + loc.y * height;

	int x2 = x1 + width;
	int y2 = y1 + height;

	/********************** CELL BORDER ***************************/
	for (int j = y1; j < y1 + borderDimension; ++j)
	{
		for (int i = x1; i < x2; ++i)
		{
			gfx.PutPixel(i, j, cBorder);
		}
	}

	for (int j = y2 - borderDimension; j < y2; ++j)
	{
		for (int i = x1; i < x2; ++i)
		{
			gfx.PutPixel(i, j, cBorder);
		}
	}

	for (int j = y1 + borderDimension; j < y2 - borderDimension; ++j)
	{
		for (int i = x1; i < x1 + borderDimension; ++i)
		{
			gfx.PutPixel(i, j, cBorder);
		}
	}

	for (int j = y1 + borderDimension; j < y2 - borderDimension; ++j)
	{
		for (int i = x2 - borderDimension; i < x2; ++i)
		{
			gfx.PutPixel(i, j, cBorder);
		}
	}
	/***************************************************************/


	x1 += borderDimension;
	x2 -= borderDimension;
	
	y1 += borderDimension;
	y2 -= borderDimension;
	
	for (int j = y1; j < y2; ++j)
	{
		for (int i = x1; i < x2; ++i)
		{
			gfx.PutPixel(i, j, c);
		}
	}

}


int Grid::GetWidth() const
{
	return width;
}
int Grid::GetHeight() const
{
	return height;
}