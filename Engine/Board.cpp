#include "Board.h"
#include <assert.h>



Board::Board(Graphics& gfx, const int boardSize)
	:
	grfx( gfx ),
	_boardOffset(boardSize)
{
	
}


Board::~Board()
{
}

void Board::drawCell(const Location& location, Color c, Color borderColour)
{
	assert(location.x >= 0);
	assert(location.x < WIDTH);
	assert(location.y >= 0);
	assert(location.y < HEIGHT);
	
	grfx.DrawRectDim(location.x * DIMENSION, location.y * DIMENSION, DIMENSION, DIMENSION, Colors::Black);
	grfx.DrawRectDim(location.x * DIMENSION + 2, location.y * DIMENSION + 2, DIMENSION - 2, DIMENSION - 2, c);

	drawBoarder(location, borderColour);
	
}

bool Board::isInsideBoard(const Location & loc) const
{
	return loc.x >= (_boardOffset / 10) && 
		   loc.x < WIDTH - (_boardOffset / 10) &&
		   loc.y >= (_boardOffset / 10) && 
		   loc.y < HEIGHT - (_boardOffset / 10);
}

void Board::drawBoarder(const Location& location, Color c) const
{
	static const Location tempLoc = location;
	grfx.DrawRectDim(tempLoc.x + _boardOffset - 40, tempLoc.y + _boardOffset - 50,
		WIDTH*DIMENSION - _boardOffset * 2, 20, c);
	grfx.DrawRectDim(tempLoc.x + _boardOffset - 40, tempLoc.y + HEIGHT*DIMENSION - _boardOffset - 30,
		WIDTH*DIMENSION - _boardOffset * 2, 20, c);

	grfx.DrawRectDim(tempLoc.x + WIDTH*DIMENSION - _boardOffset - 40, tempLoc.y + _boardOffset - 50,
		20, HEIGHT*DIMENSION - _boardOffset * 2 + 40, c);
	grfx.DrawRectDim(tempLoc.x + _boardOffset - 60, tempLoc.y + _boardOffset - 50,
		20, HEIGHT*DIMENSION - _boardOffset * 2 + 40, c);
}
