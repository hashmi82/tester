#include "Goal.h"
#include "Graphics.h"


Goal::Goal(std::mt19937& rng, Board& board, const Snake& snake, const int boardSize)
{
	respawn(rng, board, snake, boardSize);
}


Goal::~Goal()
{
}

void Goal::respawn(std::mt19937 & rng, Board & board, const Snake & snake, const int boardSize)
{
	std::uniform_int_distribution<int> xDis((boardSize / 10), (board.getGridWidth() - (boardSize/10) -1));
	std::uniform_int_distribution<int> yDis((boardSize / 10), (board.getGridHeight()- (boardSize/10) -1));

	Location newLoc;
	do {
		newLoc.x = xDis(rng);
		newLoc.y = yDis(rng);
	} while (snake.isInTile(newLoc));
	loc = newLoc;

}

void Goal::draw(Board & board) const
{
	board.drawCell(loc, c, Colors::Cyan);
}

