#pragma once


#include "Graphics.h"
#include "Location.h"
   

class Grid
{

private:

	class Border
	{
	public:
		Border(Graphics& in_gfx, int in_width, int in_height, int in_dimension, Location in_loc);
		void Draw(Color c);

	private:
		int width;
		int height;
		int dimension;

		Location pixLoc0;

		Graphics& gfx;
	};



	class Cell
	{
	public:
		Cell(Graphics& in_gfx, int in_width, int in_height, int in_borderDimension, Location in_loc0);
		void Draw(Location loc, Color c, Color cBorder);

	private:
		int width;
		int height;
		int borderDimension;
		
		Location loc0;

		Graphics& gfx;
	};




public :

	Grid(Graphics& in_gfx,
		int in_width, int in_height,
		int in_bDimension, Location in_loc,
		int in_cWidth, int in_cHeight, int in_cborderDimension);

	int GetWidth() const;
	int GetHeight() const;
	void DrawBorder(Color c);
	void DrawCell(Location loc, Color cCol, Color cBorder);

private:

	int width;
	int height;

	Border border;
	Cell cell;
};
