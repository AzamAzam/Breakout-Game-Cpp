#ifndef BREAKOUT_H
#define BREAKOUT_H
#include "menu.h"
class Breakout:public Menu 
{
    int i, cols, rows, ball_cols, ball_rows, highscore, score = 1, tries = 1, level = 1;
	char ch;
    int ball_turn=0;
    int bricks[4][40], row_index;
	bool game = true, is_direction_up_right = true, is_direction_up_left = false, is_direction_down_left = false, is_direction_down_right = false;
	bool is_direction_up_right_2_increment = false, is_direction_up_left_2_increment = false, is_coming_down_from_right = false, is_coming_down_from_left = false;
public:
    
	void startGame();
    void flagVariablesDefine();

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

	bool runGame();
	void moveUpRight();
	void moveDownRight();
	void moveUpLeft();
	void moveDownLeft();
	void moveUpLeftWith2Increment();
	void moveUpRightWith2Increment();
    bool ballStrikesToBrick();
	void setDirection();
    bool shouldBallMove();
    void moveBall();
    void goToHomeScreen();
    void resetBricks();

    void scoreBoard();
    void setHighScore();
    void gameover();
	



};

void gotoxy(short int x, short int y);
void setColor(int c);

#endif