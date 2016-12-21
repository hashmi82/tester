#pragma once
#include "Graphics.h"
#include "Board.h"
class Border
{
public:
	Border::Border();
	Border(int height, int width, int thickness,int offSet, Graphics& gfx, Board board);
	~Border();
	void drawBorder(Graphics& gfx, Board board);
private:
	
	int _height;
	int _width;
	int _thickness;
	int _borderOffset;

};

