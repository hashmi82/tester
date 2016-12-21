#include "Snake.h"



Snake::Snake(const Location& loc)
{
	segments[0].initHead(loc);
}


Snake::~Snake()
{
}

void Snake::moveBy(const Location & delta_loc)
{
	for (int i = nSegments - 1; i > 0; --i)
		segments[i].follow(segments[i - 1]);

	segments[0].moveBy(delta_loc);
}

void Snake::grow()
{
	segments[nSegments].initBody(nSegments);
	++nSegments;
}
void Snake::draw(Board& board)
{
	for (int i = 0; i < nSegments; ++i) { segments[i].draw(board); }
}

Location Snake::getNextHeadPos(const Location delta_loc) const
{
	Location l(segments[0].getLocation());
	l.add(delta_loc);
	return l;
	
}

bool Snake::isInTileExceptEnd(const Location& targetLoc) const
{
	for (int i = 0; i < nSegments - 1; ++i)
	{
		if (segments[i].getLocation() == targetLoc) { return true; }
		
	}
	return false;
}

bool Snake::isInTile(const Location & targetLoc) const
{
	for (int i = 0; i < nSegments; ++i)
	{
		if (segments[i].getLocation() == targetLoc) { return true; }

	}
	return false;
	
}

void Snake::Segment::initHead(const Location & in_loc)
{
	
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::initBody(int nSeg)
{
	
		if (nSeg % 1 == 0) { c = Colors::Green; }
		if (nSeg % 3 == 0) { c = Colors::MakeRGB(100, 200, 100); }
		if (nSeg % 2 == 0) { c = Colors::MakeRGB(150, 50, 150); }
		if (nSeg % 5 == 0) { c = Colors::MakeRGB(150, 105, 150); }
		
		
	
	
}

void Snake::Segment::follow(const Segment & next)
{
	loc = next.loc;
}

void Snake::Segment::moveBy(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.add(delta_loc);
}

void Snake::Segment::draw(Board & board)
{

	board.drawCell(loc, c, Colors::Cyan); 
	
	
}

