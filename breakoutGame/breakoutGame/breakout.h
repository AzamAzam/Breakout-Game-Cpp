#ifndef BREAKOUT_H
#define BREAKOUT_H

class Breakout
{
	int i, cols, rows, ball_cols, ball_rows, sleep = 100, score = 0, tries = 1;
	char ch;
	int bricks[75];
	bool game = true, is_direction_up_right = true, is_direction_up_left = false, is_direction_down_left = false, is_direction_down_right = false;
	bool is_direction_up_right_2_increment = false, is_direction_up_left_2_increment = false, is_coming_down_from_right = false, is_coming_down_from_left = false;
public:
	void startgame();

	void drawBoundary();
	void drawUperHorizontalWall();
	void drawLowerHorizontalWall();
	void drawVerticalWalls();
	void drawStripeAndStriker();
	void drawTiles();

	void keysHandling();
	void rightArrowkey();
	void leftArrowkey();
	void upArrowkey();
	void DownArrowkey();
	void spacekey();

	bool gameRunning();
	void moveUpRight();
	void moveDownRight();
	void moveUpLeft();
	void moveDownLeft();
	void moveUpLeftWith2Increment();
	void moveUpRightWith2Increment();
	void setDirection();

    void scoreBoard();
	
	
	



};

void gotoxy(short int x, short int y);
void setColor(int c);

#endif