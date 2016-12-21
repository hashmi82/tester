#include "Border.h"




Border::Border()
{

}

Border::Border(int height, int width, int thickness,int offSet, Graphics& gfx, Board board)
	:
	_height(height),
	_width(width),
	_thickness(thickness),
	_borderOffset(offSet)
{
	drawBorder(gfx, board);
}

Border::~Border()
{
}

void Border::drawBorder(Graphics& gfx, Board board)
{
	//for (int i = 10; i < 790; ++i)
		//gfx.PutPixel(i, 10, 255, 255, 255);
	
	//for (int i = 790; i > 10; --i)
		//gfx.PutPixel(i, 590, 255, 255, 255);
	
	//for (int i = 10; i < 590; ++i)
		//gfx.PutPixel(10, i, 255, 255, 255);
	
	//for (int i = 590; i > 10; --i)
		//gfx.PutPixel(790, i, 255, 255, 255);
}
