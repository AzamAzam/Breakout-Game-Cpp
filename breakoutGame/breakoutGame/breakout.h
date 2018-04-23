/*
Bcsf15m017  Muhammad Azam
Bcsf15m022   Naman Ali Khan
*/

#ifndef BREAKOUT_H
#define BREAKOUT_H
#include "menu.h"
class Breakout:public Menu 
{
	int i, stripe_cols, upper_stripe_rows, down_stripe_rows, ball_cols, ball_rows, highscore, tries, level, sleep;
    int score,lives ;
    char ch;
    int ball_turn;
    int bricks[4][40], row_index;
	bool game, is_direction_up_right, is_direction_up_left, is_direction_down_left, is_direction_down_right;
	bool is_direction_up_right_2_increment, is_direction_up_left_2_increment;
	bool is_coming_from_right, is_coming_from_left;
public:
    
    void resetGameVaribles();
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
	void downArrowkey();
	void pauseGame();

	void runGame();
    void playGame();

	void moveUpRight();
	void moveDownRight();
	void moveUpLeft();
	void moveDownLeft();
	void moveUpLeftWith2Increment();
	void moveUpRightWith2Increment();
	
    bool ballStrikesToBrick();
	void setDirection();
	void ballStrikeToLowerStripe();
	void ballStrikeToUpperStripe();
    bool shouldBallMove();
    void moveBall();
    void goToHomeScreen();
    void resetBricks();

    void scoreBoard();
    void setHighScore();
    void gameover();
    void exitIt();
    void showButtons();



};

void gotoxy(short int x, short int y);
void setColor(int c);

#endif