
#include "Location.h"
#include "Colors.h"
#include "Grid.h"
#include "Keyboard.h"



class Tetrimino
{

public:

	Tetrimino(Location in_locCell[4], Color in_c);
	
	void Draw(Grid& grid);
	void Move(Keyboard& kbd, Grid& grid, int speedY);

private:

	
	Location locCell[4];
	Color c;

};