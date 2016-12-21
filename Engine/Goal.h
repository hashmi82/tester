#pragma once
#include "Snake.h"
#include "Board.h"
#include <random>
#include <time.h>
#include "Graphics.h"
class Goal
{
public:
	Goal(std::mt19937& rng, Board& board, const Snake& snake, const int boardSize);
	~Goal();
	void respawn(std::mt19937& rng, Board& board, const Snake& snake, const int boardSize);
	void draw(Board& board) const;
	const Location& getLocation() const { return loc; }
private:

	static constexpr Color c = Colors::Red;
	Location loc;
	
};

