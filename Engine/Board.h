#pragma once
#include "Graphics.h"
#include "Location.h"
class Board
{
public:
	Board(Graphics& gfx, const int boardSize);
	~Board();

	void drawCell(const Location& location, Color c, Color borderColour);
	int getGridWidth() { return WIDTH; }
	int getGridHeight() { return HEIGHT; }
	bool isInsideBoard( const Location& loc) const;
	

private:
	void drawBoarder(const Location& location, Color c)const;
	static constexpr int DIMENSION = 10;
	static constexpr int WIDTH = 80;
	static constexpr int HEIGHT = 60;
	int _boardOffset;
	
	

	Graphics& grfx;
};

