#pragma once
#include "Board.h"
#include "Location.h"
#include <vector>
#include <assert.h>
class Snake
{


	

private:
	class  Segment
	{
	public:
		
		void initHead(const Location& loc);
		void initBody(int nSeg);
		void follow(const Segment& next);
		void moveBy(const Location& delta_loc);
		void draw(Board& board);
		const Location& getLocation() const { return loc; }
	private:
	
		Location loc;
		Color c;
		
		
	};
public:
	Snake(const Location& loc);
	~Snake();
	void moveBy(const Location& delta_loc);
	void grow();
	void draw(Board& board);
	Location getNextHeadPos( const Location delta_loc) const;
	bool isInTileExceptEnd(const Location& targetLoc) const;
	bool isInTile(const Location& targetLoc) const;
	int getNSeg() { return nSegments; }
private:
	
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	
	static constexpr int MAX_SIZE = 1000;
	Segment segments[MAX_SIZE];
	int nSegments = 1;
};


