/*
Bcsf15m017  Muhammad Azam
Bcsf15m022   Naman Ali Khan
*/

#include"breakout.h"

void gotoxy ( short int x, short int y )
{
	COORD cur = { x, y }; SetConsoleCursorPosition ( GetStdHandle ( STD_OUTPUT_HANDLE ), cur );
}

void setColor ( int c )
{
	HANDLE hConsole = GetStdHandle ( STD_OUTPUT_HANDLE );
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo ( hConsole, &csbi );
	SetConsoleTextAttribute ( hConsole, ( csbi.wAttributes & 0xFFF0 ) | ( WORD ) c ); // For ground colors take up the least significant byte
}


void Breakout::drawBoundary ( )
{
	drawUperHorizontalWall ( );
	drawVerticalWalls ( );
	drawLowerHorizontalWall ( );


}
void Breakout::drawUperHorizontalWall ( )
{

	gotoxy ( 20, 4 );    // upper horizontal wall
	for ( int i = 1; i <= 40; i++ )
	{
		setColor ( 14 );
		cout << char ( 220 );
	}

}
void Breakout::drawVerticalWalls ( )
{

	for ( i = 5; i <= 30; i++ )    // vertical walls
	{
		setColor ( 14 );
		gotoxy ( 20, i );  //left vertical wal 
		cout << char ( 219 );
		gotoxy ( 59, i );     //right vertical wall
		cout << char ( 219 ) << endl;
	}
}
void Breakout::drawLowerHorizontalWall ( )
{

	gotoxy ( 20, 31 );    // lower horizontal wall
	for ( int j = 1; j <= 40; j++ )
	{
		setColor ( 14 );
		cout << char ( 223 );
	}
}
void Breakout::drawStripeAndStriker ( )
{
	setColor ( 11 );

	for ( int r = 24; r <= 30; r++ ) //clear last 5 rows  
	{
		gotoxy ( 21, r );
		cout << "                                      ";
		gotoxy ( 21, 5 );			//clear first row
		cout << "                                      ";

	}

	gotoxy ( stripe_cols, upper_stripe_rows );   // upper stripe
	for ( int j = 1; j <= 5; j++ )
		cout << char ( 220 );


	gotoxy (stripe_cols, down_stripe_rows );   // down stripe
	for ( int j = 1; j <= 5; j++ )
		cout << char ( 223 );

	gotoxy ( ball_cols, down_stripe_rows - 1 );   // striker
	cout << "O";
}
void Breakout::drawTiles ( )
{
	sleep = 50;
	gotoxy ( 22, 11 );	   // line 1 of tiles
	cout << " ";
	bricks[0][0] = 0;
	for ( int i = 1; i <= 35; i += 3 )
	{
		setColor ( 12 );
		bricks[0][i] = 1;
		bricks[0][i + 1] = 1;
		bricks[0][i + 2] = 0;


		cout << char ( 223 ) << char ( 223 ) << " ";
	}
	if ( level == 2 )
	{
		sleep = 40;

		gotoxy ( 22, 12 );	   // line 2 of tiles
		cout << "   ";
		bricks[1][0] = 0;
		bricks[1][1] = 0;
		bricks[1][2] = 0;

		for ( int i = 3; i <= 35; i += 7 )
		{
			setColor ( 5 );
			bricks[1][i] = 1;
			bricks[1][i + 1] = 1;
			bricks[1][i + 2] = 0;
			bricks[1][i + 3] = 0;
			bricks[1][i + 4] = 0;
			bricks[1][i + 5] = 0;
			bricks[1][i + 6] = 0;
			cout << char ( 223 ) << char ( 223 ) << "     ";
		}
		gotoxy ( 22, 13 );	   // line 3 of tiles
		cout << "   ";
		bricks[2][0] = 0;
		bricks[1][0] = 0;
		bricks[1][1] = 0;
		bricks[1][2] = 0;
		for ( int i = 3; i <= 35; i += 7 )
		{

			setColor ( 5 );
			bricks[2][i] = 1;
			bricks[2][i + 1] = 1;
			bricks[2][i + 2] = 0;
			bricks[2][i + 3] = 0;
			bricks[2][i + 4] = 0;
			bricks[2][i + 5] = 0;
			bricks[2][i + 6] = 0;
			cout << char ( 223 ) << char ( 223 ) << "     ";
		}
		gotoxy ( 22, 14 );	   // line 4 of tiles
		cout << " ";
		bricks[3][0] = 0;
		for ( int i = 1; i <= 35; i += 3 )
		{
			setColor ( 7 );
			bricks[3][i] = 1;
			bricks[3][i + 1] = 1;
			bricks[3][i + 2] = 0;


			cout << char ( 223 ) << char ( 223 ) << " ";
		}

	}
	else if ( level == 3 )
	{
		sleep = 30;

		gotoxy ( 22, 12 );	   // line 2 of tiles
		cout << "    ";
		bricks[1][0] = 0;
		bricks[1][1] = 0;
		bricks[1][2] = 0;
		bricks[1][3] = 0;

		for ( int i = 4; i <= 32; i += 3 )
		{
			setColor ( 12 );
			bricks[1][i] = 1;
			bricks[1][i + 1] = 1;
			bricks[1][i + 2] = 0;


			cout << char ( 223 ) << char ( 223 ) << " ";
		}

		gotoxy ( 22, 13 );	   // line 3 of tiles
		cout << "       ";
		bricks[2][0] = 0;
		bricks[2][1] = 0;
		bricks[2][2] = 0;
		bricks[2][3] = 0;
		bricks[2][4] = 0;
		bricks[2][5] = 0;
		bricks[2][6] = 0;
		for ( int i = 7; i <= 28; i += 3 )
		{
			setColor ( 12 );
			bricks[2][i] = 1;
			bricks[2][i + 1] = 1;
			bricks[2][i + 2] = 0;


			cout << char ( 223 ) << char ( 223 ) << " ";
		}

		gotoxy ( 22, 14 );	   // line 4 of tiles

		for ( int i = 0; i < 10; i++ )
		{
			bricks[3][i] = 0;
			cout << " ";
		}

		for ( int i = 10; i <= 27; i += 3 )
		{
			setColor ( 12 );
			bricks[3][i] = 1;
			bricks[3][i + 1] = 1;
			bricks[3][i + 2] = 0;


			cout << char ( 223 ) << char ( 223 ) << " ";
		}
	}
}

void Breakout::flagVariablesDefine()

{

    game = true; is_direction_up_right = true; is_direction_up_left = false; is_direction_down_left = false; is_direction_down_right = false;
    is_direction_up_right_2_increment = false; is_direction_up_left_2_increment = false;

    is_coming_from_right = false; is_coming_from_left = false;

}
void Breakout::resetBricks()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            bricks[i][j] = 0;
        }
    }

}
void Breakout::resetGameVaribles()
{
    lives = 3;
    level = 1;
    tries = 1;
    score = 0;
    ball_turn = 0;

}

void Breakout::keysHandling ( )
{

	ch = _getch ( );

	if ( ch <= 0 )
	{
		ch = _getch ( );
		
			if ( ch == 77 )  // right arrow key
			{
				rightArrowkey ( );
			}
			else if ( ch == 75 )  // left arrow key
			{
				leftArrowkey ( );
			}
			else if ( ch == 72 ) // up arrow key
			{
				upArrowkey ( );
			}
			else if ( ch == 80 ) // down arrow key
			{
				downArrowkey ( );
			}
		
		else
			cout << "\a";
	}
    else if (ch == 32)
    
        pauseGame();
    
    else if (ch == 27)
    
        exitIt();
    
    else if (ch == 8)
    {
        setColor(12);
        char ch;
        gotoxy(62, 30);
        cout << "                                                    "; //hide buttons 

        gotoxy(65, 11);
        cout << "Are You Sure You Want to go to Menu ";
        gotoxy(65, 13);
        cout << "Y = Yes      Any key = continue ";
        gotoxy(65, 15);
        ch = _getche();
        if (ch == 'y' || ch == 'Y')
        {

            home_screen();
        }
        else
        {
            gotoxy(65, 11);
            cout << "                                   ";
            gotoxy(65, 13);
            cout <<"                                     ";

            showButtons();
        }
    }
    else 
		cout << "\a";
}
void Breakout::upArrowkey ( )
{

	if ( down_stripe_rows > 24 && ( down_stripe_rows - ball_rows > 2 ) ) //stripe moves till bricks 
	{
		down_stripe_rows--;
		gotoxy (stripe_cols, down_stripe_rows + 1 );
		cout << "     ";
		gotoxy (stripe_cols, down_stripe_rows );
		cout << char ( 223 ) << char ( 223 ) << char ( 223 ) << char ( 223 ) << char ( 223 );

	}
	else
		cout << "\a";

}
void Breakout::downArrowkey ( )
{


	if ( down_stripe_rows < 30 ) //stripe cant move down to lower wall
	{
        down_stripe_rows++;
		gotoxy (stripe_cols, down_stripe_rows - 1 );
		cout << "     ";
		gotoxy (stripe_cols, down_stripe_rows );
		cout << char ( 223 ) << char ( 223 ) << char ( 223 ) << char ( 223 ) << char ( 223 );

	}
	else
		cout << "\a";

}
void Breakout::leftArrowkey ( )
{

	stripe_cols--;
	if (stripe_cols >= 21 )//it stops strips to left wall
	{
		gotoxy (stripe_cols + 5, down_stripe_rows );
		cout << " ";
		gotoxy (stripe_cols, down_stripe_rows );
		cout << char ( 223 );

		gotoxy (stripe_cols + 5, upper_stripe_rows );
		cout << " ";
		gotoxy (stripe_cols, upper_stripe_rows );
		cout << char ( 220 );
	}
	else
	{
		cout << "\a";
		stripe_cols++;
	}
}
void Breakout::rightArrowkey ( )
{
    stripe_cols++;
	if (stripe_cols <= 54 )   //it stops to right wall
	{
		gotoxy (stripe_cols - 1, down_stripe_rows );
		cout << " ";
		gotoxy (stripe_cols + 4, down_stripe_rows );
		cout << char ( 223 );

		gotoxy (stripe_cols - 1, upper_stripe_rows );
		cout << " ";
		gotoxy (stripe_cols + 4, upper_stripe_rows );
		cout << char ( 220 );
	}
	else
	{
		cout << "\a";
		stripe_cols--;
	}
}
void Breakout::pauseGame()
{
    char ch;
    //it pauses the game 
    gotoxy(62, 30);
    cout << "                                                    "; //hide buttons 

    gotoxy(24, 20);
    cout << "Press Space Key to continue . . . ";
    do {
        ch = _getch();
        if (ch == 32)
        {
            gotoxy(24, 20);
            cout << "                                  ";
        }
        else cout << "\a";
    } while (ch != 32);
    showButtons();
}
void Breakout::showButtons()
{

    setColor(9);
    gotoxy(62, 30);
    cout << "   Space = Pause     Esc = Exit     Backspace = Menu ";
}

bool Breakout::shouldBallMove()
{
    ball_turn++;
    if (ball_turn == 3)
    {
        ball_turn = 0;
        return true;
    }
    else
        return false;
}
void Breakout::startGame()

{
    system("cls");



    flagVariablesDefine();
    resetBricks();
    resetGameVaribles();
    drawTiles();

    drawBoundary();

    playGame();


}
void Breakout::runGame ( )
{
    
	while ( game )
    {
		

		if ( _kbhit ( ) )
		{
			keysHandling ( );

		}

        setColor(11);
		if ( shouldBallMove ( ) )
		{
			moveBall ( );


		}
		



        if (ball_rows >= 30 || ball_rows <= 5)   //chance lose 
        {
            lives--;

            gotoxy(65, 16);
            cout << "Lives : " << lives;

            if (lives <= 0)

                gameover();
            else
            {
                pauseGame();
                playGame();
            }
        }


		if ( score == 12 && level == 1 || score == 46 && level == 2 )
		{
			game = false;
			level++;


			startGame ( );
		}
		else if ( score >= 82 && level == 3 )
		{
			game = false;
			gotoxy ( 35, 15 );
			cout << "Game End !!!";
			gotoxy ( 35, 16 );
			cout << "Congrats !!!";

			setHighScore ( );

			goToHomeScreen ( );

		}
		Sleep ( sleep );
	}

}
void Breakout::playGame ( )
{
	scoreBoard ( );

	stripe_cols = 37, down_stripe_rows = 30; upper_stripe_rows = 5;
	ball_rows = down_stripe_rows - 1, ball_cols = 39; 

	drawStripeAndStriker ( );
	flagVariablesDefine ( );

	gotoxy ( 65, 16 );
	cout << "Lives : " << lives;

	
	gotoxy ( 36, 18 );
	cout << "Level " << level;

	Sleep ( 1000 );

	gotoxy ( 36, 18 );
	cout << "        ";

    pauseGame();
    showButtons();
	runGame ( );

}

void Breakout::moveBall ( ){

	if ( is_direction_up_right )
		moveUpRight ( );

	else if ( is_direction_down_left )
		moveDownLeft ( );

	else if ( is_direction_down_right )
		moveDownRight ( );

	else if ( is_direction_up_left )
		moveUpLeft ( );

	else if ( is_direction_up_left_2_increment )
		moveUpLeftWith2Increment ( );

	else if ( is_direction_up_right_2_increment )
		moveUpRightWith2Increment ( );

	
	setDirection ( );

	if ( ball_cols == 59 || ball_cols == 20 )
		drawVerticalWalls ( );

}
void Breakout::moveUpRight ( )
{

	gotoxy ( ball_cols, ball_rows );
	cout << " ";
	gotoxy ( ++ball_cols, --ball_rows );
	cout << "O";


	is_coming_from_left = false;
	is_coming_from_right = false;

	if ( ballStrikesToBrick ( ) )
	{

		is_direction_up_right = false;
		is_direction_down_right = true;
	}
	else if ( ball_rows == upper_stripe_rows+ 1 && ball_cols >= stripe_cols - 1 && ball_cols <= stripe_cols + 5 ) //bal hits the stripe
	{
		is_coming_from_left = true;
		is_direction_up_right = false;
	}
	else if ( ball_cols >= 58 ) //ball strikes to right wall
	{
		is_direction_up_right = false;
		is_direction_up_left = true;

	}


}
void Breakout::moveUpLeft ( )
{

	gotoxy ( ball_cols, ball_rows );
	cout << " ";
	gotoxy ( --ball_cols, --ball_rows );
	cout << "O";

	is_coming_from_right = false;
	is_coming_from_left = false;

	if ( ballStrikesToBrick ( ) )
	{

		is_direction_up_left = false;
		is_direction_down_left = true;

	}
	else if ( ball_rows ==upper_stripe_rows + 1 && ball_cols >=stripe_cols - 1 && ball_cols <=stripe_cols + 5 ) //bal hits the stripe
	{
		is_coming_from_right = true;
		is_direction_up_left = false;
	}
	else if ( ball_cols <= 21 ) //bal strikes left wall
	{
		is_direction_up_left = false;
		is_direction_up_right = true;

	}

}
void Breakout::moveDownLeft ( )
{

	gotoxy ( ball_cols, ball_rows );
	cout << " ";
	gotoxy ( --ball_cols, ++ball_rows );
	cout << "O";
	is_coming_from_right = false ;
	is_coming_from_left = false;
	if ( ballStrikesToBrick ( ) )
	{
		is_direction_down_left = false;
		is_direction_up_left = true;
	}

	else if ( ball_rows == down_stripe_rows - 1 && ball_cols >=stripe_cols - 1 && ball_cols <=stripe_cols + 5 ) //bal hits the stripe
	{
		is_direction_down_left = false;
		is_coming_from_right = true;
	}
	else if ( ball_cols <= 21 )//ball strikes left wall
	{
		is_direction_down_left = false;
		is_direction_down_right = true;
	}


}
void Breakout::moveDownRight ( )
{

	gotoxy ( ball_cols, ball_rows );
	cout << " ";

	gotoxy ( ++ball_cols, ++ball_rows );
	cout << "O";

	is_coming_from_left = false ;
	is_coming_from_right = false;
	
	if ( ballStrikesToBrick ( ) )
	{
		is_direction_down_right = false;
		is_direction_up_right = true;
	}
	else if ( ball_rows == down_stripe_rows - 1 && ball_cols >=stripe_cols - 1 && ball_cols <=stripe_cols + 5 ) //bal hits the stripe
	{
		is_coming_from_left = true;
		is_direction_down_right = false;
	}
	else if ( ball_cols >= 58 )//bal strikes to left wall 
	{
		is_direction_down_right = false;
		is_direction_down_left = true;
	}



}
void Breakout::moveUpRightWith2Increment ( )
{

	gotoxy ( ball_cols, ball_rows );
	cout << " ";
	gotoxy ( ball_cols += 2, --ball_rows );
	cout << "O";

	if ( ballStrikesToBrick ( ) )
	{

		is_direction_up_right_2_increment = false;
		is_direction_down_right = true;

	}
	if ( ball_cols >= 57 )
	{
		is_direction_up_right_2_increment = false;
		is_direction_up_left = true;
	}
}
void Breakout::moveUpLeftWith2Increment ( )

{

	gotoxy ( ball_cols, ball_rows );
	cout << " ";
	gotoxy ( ball_cols -= 2, --ball_rows );
	cout << "O";

	if ( ballStrikesToBrick ( ) )
	{

		is_direction_up_left_2_increment = false;
		is_direction_down_left = true;

	}

	if ( ball_cols <= 22 )
	{
		is_direction_up_left_2_increment = false;
		is_direction_up_right = true;

	}

}

void Breakout::setDirection ( )
{
	if ( ball_rows == down_stripe_rows - 1 )
		ballStrikeToLowerStripe ( );
	if ( ball_rows == upper_stripe_rows + 1 )
		ballStrikeToUpperStripe ( );




}
void Breakout::ballStrikeToLowerStripe ( )
{

	if ( ( ball_cols ==stripe_cols  && ball_cols <= 21 )  //ball is at down left corner 
		|| ( ( ball_cols ==stripe_cols + 3 || ball_cols ==stripe_cols + 5 ) &&  ball_cols < 57  )  //ball hits the stripe  on right side 
		|| ( is_coming_from_left &&ball_cols ==stripe_cols + 2 ) ) //bal hits in mid of stripe 

	{
		tries++;
		scoreBoard ( );
		is_direction_up_right = true;
	}
	else if ( ( ( ball_cols ==stripe_cols + 3 || ball_cols ==stripe_cols + 5 ) && ball_cols >= 57 ) //ball is in right down corner 
		|| ( ( ball_cols ==stripe_cols + 1 || ball_cols ==stripe_cols - 1) &&  ball_cols > 21  ) //ball  hits  the stripe on left side 
		|| ( is_coming_from_right &&ball_cols ==stripe_cols + 2 ) ) // bal hits in mid of stripe 

	{
		tries++;
		scoreBoard ( );
		is_direction_up_left = true;
	}

	else if ( ball_cols ==stripe_cols + 4 )
	{
		tries++;
		scoreBoard ( );
		if ( ball_cols >= 56 )
			is_direction_up_left = true;
		else
			is_direction_up_right_2_increment = true;
	}
	else if ( ball_cols ==stripe_cols )
	{
		tries++;
		scoreBoard ( );
		if ( ball_cols <= 22 )
			is_direction_up_right = true;
		else
			is_direction_up_left_2_increment = true;
	}

}
void Breakout::ballStrikeToUpperStripe ( )
{

	if ( ( ball_cols ==stripe_cols   && ball_cols <= 21 )  //ball is at upper left corner 
		|| ( ( ball_cols == stripe_cols + 3 || ball_cols == stripe_cols + 4 || ball_cols == stripe_cols + 5 ) && ball_cols < 57 )  //ball hits the stripe  on right side 
		|| ( is_coming_from_left &&ball_cols ==stripe_cols + 2 ) ) //bal hits in mid of stripe 

	{
		tries++;
		scoreBoard ( );
		is_direction_down_right = true;
	}
	else if ( ( ( ball_cols == stripe_cols + 3 || ball_cols == stripe_cols + 4 || ball_cols == stripe_cols + 5 ) && ball_cols >= 57 ) //ball is in right upper corner 
		|| ( ( ball_cols == stripe_cols - 1 || ball_cols == stripe_cols ||  ball_cols == stripe_cols + 1 ) && ball_cols >= 22 ) //ball  hits  the stripe on left side 
		|| ( is_coming_from_right &&ball_cols ==stripe_cols + 2 ) ) // bal hits in mid of stripe 

	{
		tries++;
		scoreBoard ( );
		is_direction_down_left = true;
	}

	


}
bool Breakout::ballStrikesToBrick ( )
{
	row_index = ball_rows - 11;
	if ( row_index < 4 &&row_index>=0)
	{
		if ( bricks[row_index][ball_cols - 22] == 1 && ball_rows == row_index + 11 )//when bal hits to a brick
		{

			bricks[row_index][ball_cols - 22] = 0;  //index where bal hits 
			bricks[row_index][ball_cols - 21] = 0;  // next  index 
			bricks[row_index][ball_cols - 23] = 0; //pervious index

			gotoxy ( ball_cols - 1, ball_rows );
			cout << "   ";

			score++;
			scoreBoard ( );
			return true;
		}
	}
	
		return false;
}


void Breakout::scoreBoard ( )
{
	setColor ( 11 );
	gotoxy ( 65, 18 );
	cout << "                          ";
	gotoxy ( 65, 18 );
	cout << "Tries : " << tries;
	gotoxy ( 65, 20 );
	cout << "                          ";
	gotoxy ( 65,20);
	cout << "Scores : " << score;

}
void Breakout::setHighScore ( )
{
	fstream file;
	file.open ( "high score.txt", ios::in );
	if ( !file )
	{
		highscore = 0;
	}
	else
	{
		file >> highscore;

	}
	file.close ( );

	if ( highscore < score )
	{
		file.open ( "high score.txt", ios::out );
		highscore = score;
		file << highscore;
		file.close ( );
	}
}
void Breakout::gameover ( )
{
    setColor(9);
	game = false;
    gotoxy(62, 30);
    cout << "Enter = Play Again ";
	gotoxy ( 35, 16 );
	cout << "Game Over !!!";

	setHighScore ( );

	goToHomeScreen ( );

}
void Breakout::goToHomeScreen ( )
{
	ch = _getch ( );
	while ( !( ch == 8 ||ch==13||ch==10) )
	{
         if (ch == 27)
            exitIt();
         else 
             cout << "\a";
		ch = _getch ( );
	}

	if ( ch == 8 )
    {
		home_screen ( );
	}
	

    else if (ch == 13 || ch == 10)
    {
        resetGameVaribles();
        startGame();
    }
    
}
void Breakout::exitIt()
{
    setColor(12);
    char ch;
    gotoxy(62, 30);
    cout << "                                                    "; //hide buttons 

    gotoxy(65, 11);
    cout << "Are You Sure You Want to Exit ";
    gotoxy(65, 13);
    cout << "Y = Yes      Any key = continue ";
    gotoxy(65, 15);
    ch = _getche();
    if (ch == 'y' || ch == 'Y')
    {
        system("cls");
        setColor(9);
        gotoxy(55, 13);

        cout << "Good Bye !!!";
        gotoxy(47, 17);
        _getch();
        exit(1); 
    }
    else
    {
        gotoxy(65, 11);
        cout << "                             ";
        gotoxy(65, 13);
        cout << "                               ";
        gotoxy(65, 15);
        cout << "  ";
        showButtons();
       
    }
}
