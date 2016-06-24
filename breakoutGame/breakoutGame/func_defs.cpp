#include"breakout.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>

using namespace std;

void gotoxy(short int x, short int y)
{
    COORD cur = { x, y }; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

void setColor(int c)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xFFF0) | (WORD)c); // For ground colors take up the least significant byte
}

void Breakout::flagVariablesDefine()
{

    game = true; is_direction_up_right = true; is_direction_up_left = false; is_direction_down_left = false; is_direction_down_right = false;
    is_direction_up_right_2_increment = false; is_direction_up_left_2_increment = false; is_coming_down_from_right = false; is_coming_down_from_left = false;
}
void Breakout::startGame()
{
    system("cls");

    flagVariablesDefine();

    resetBricks();
    drawTiles();

    drawBoundary();

    cols = 38, rows = 30;
    ball_rows = rows - 1, ball_cols = 40;

    drawStripeAndStriker();

    gotoxy(36, 18);
    cout << "Level " << level;
    Sleep(1000);
    gotoxy(36, 18);
    cout << "        ";
    gotoxy(25, 20);
    system("pause");
    gotoxy(25, 20);
    cout << "                                ";
    runGame();

}

void Breakout::drawBoundary()
{
    drawUperHorizontalWall();
    drawVerticalWalls();
    drawLowerHorizontalWall();


}

void Breakout::drawUperHorizontalWall()
{

    gotoxy(20, 4);    // upper horizontal wall
    for (int i = 1; i <= 40; i++)
    {
        setColor(14);
        cout << char(220);
    }

}
void Breakout::drawVerticalWalls()
{

    for (i = 5; i <= 30; i++)    // vertical walls
    {
        setColor(14);
        gotoxy(20, i);  //left vertical wal 
        cout << char(219);
        gotoxy(59, i);     //right vertical wall
        cout << char(219) << endl;
    }
}
void Breakout::drawLowerHorizontalWall()
{
    //i=31
    gotoxy(20, i);    // lower horizontal wall
    for (int j = 1; j <= 40; j++)
    {
        setColor(14);
        cout << char(223);
    }
}
void Breakout::drawStripeAndStriker()
{
    //i=31
    gotoxy(cols, rows);   // stripe
    for (int j = 1; j <= 5; j++)
    {
        setColor(3);
        cout << char(223);
    }
    gotoxy(ball_cols, rows - 1);   // striker
    {
        setColor(3);
        cout << 'O';
    }
}

void Breakout::drawTiles()
{

    gotoxy(22, 6);	   // line 1 of tiles
    cout << " ";
    bricks[0][0] = 0;
    for (int i = 1; i <= 35; i += 3)
    {
        setColor(12);
        bricks[0][i] = 1;
        bricks[0][i + 1] = 1;
        bricks[0][i + 2] = 0;


        cout << char(223) << char(223) << " ";
    }
    if (level == 2)
    {


        gotoxy(22, 7);	   // line 2 of tiles
        cout << "   ";
        bricks[1][0] = 0;
        bricks[1][1] = 0;
        bricks[1][2] = 0;

        for (int i = 3; i <= 35; i += 7)
        {
            setColor(5);
            bricks[1][i] = 1;
            bricks[1][i + 1] = 1;
            bricks[1][i + 2] = 0;
            bricks[1][i + 3] = 0;
            bricks[1][i + 4] = 0;
            bricks[1][i + 5] = 0;
            bricks[1][i + 6] = 0;
            cout << char(223) << char(223) << "     ";
        }
        gotoxy(22, 8);	   // line 3 of tiles
        cout << "   ";
        bricks[2][0] = 0;
        bricks[1][0] = 0;
        bricks[1][1] = 0;
        bricks[1][2] = 0;
        for (int i = 3; i <= 35; i += 7)
        {

            setColor(5);
            bricks[2][i] = 1;
            bricks[2][i + 1] = 1;
            bricks[2][i + 2] = 0;
            bricks[2][i + 3] = 0;
            bricks[2][i + 4] = 0;
            bricks[2][i + 5] = 0;
            bricks[2][i + 6] = 0;
            cout << char(223) << char(223) << "     ";
        }
        gotoxy(22, 9);	   // line 4 of tiles
        cout << " ";
        bricks[3][0] = 0;
        for (int i = 1; i <= 35; i += 3)
        {
            setColor(7);
            bricks[3][i] = 1;
            bricks[3][i + 1] = 1;
            bricks[3][i + 2] = 0;


            cout << char(223) << char(223) << " ";
        }

    }
    else if (level == 3)
    {
        gotoxy(22, 7);	   // line 2 of tiles
        cout << "    ";
        bricks[1][0] = 0;
        bricks[1][1] = 0;
        bricks[1][2] = 0;
        bricks[1][3] = 0;

        for (int i = 4; i <= 32; i += 3)
        {
            setColor(12);
            bricks[1][i] = 1;
            bricks[1][i + 1] = 1;
            bricks[1][i + 2] = 0;


            cout << char(223) << char(223) << " ";
        }

        gotoxy(22, 8);	   // line 3 of tiles
        cout << "       ";
        bricks[2][0] = 0;
        bricks[2][1] = 0;
        bricks[2][2] = 0;
        bricks[2][3] = 0;
        bricks[2][4] = 0;
        bricks[2][5] = 0;
        bricks[2][6] = 0;
        for (int i = 7; i <= 28; i += 3)
        {
            setColor(12);
            bricks[2][i] = 1;
            bricks[2][i + 1] = 1;
            bricks[2][i + 2] = 0;


            cout << char(223) << char(223) << " ";
        }

        gotoxy(22, 9);	   // line 4 of tiles
        
        for (int i = 0; i < 10; i++)
        {
            bricks[3][i] = 0;
            cout << " ";
        }
        
        for (int i = 10; i <= 27; i += 3)
        {
            setColor(12);
            bricks[3][i] = 1;
            bricks[3][i + 1] = 1;
            bricks[3][i + 2] = 0;


            cout << char(223) << char(223) << " ";
        }
    }
}

void Breakout::keysHandling()
{

    ch = _getch();

    if (ch <= 0)
    {
        ch = _getch();
        if (ch == 77 || ch == 75 || ch == 72 || ch == 80)
        {
            if (ch == 77)  // right arrow key
            {
                rightArrowkey();
            }
            else if (ch == 75)  // left arrow key
            {
                leftArrowkey();
            }
            else if (ch == 72) // up arrow key
            {
                upArrowkey();
            }
            else if (ch == 80) // down arrow key
            {
                DownArrowkey();
            }
        }
        else
            cout << "\a";
    }
    else if (ch == 32)
    {
        spacekey();
    }
    else
        cout << "\a";
}

void Breakout::upArrowkey()
{

    if (rows > 24 && (rows - ball_rows > 2)) //stripe moves till bricks 
    {
        --rows;
        gotoxy(cols, rows + 1);
        cout << "     ";
        gotoxy(cols, rows);
        cout << char(223) << char(223) << char(223) << char(223) << char(223);

    }
    else
        cout << "\a";

}
void Breakout::DownArrowkey()
{


    if (rows < 30) //stripe cant move down to lower wall
    {
        ++rows;
        gotoxy(cols, rows - 1);
        cout << "     ";
        gotoxy(cols, rows);
        cout << char(223) << char(223) << char(223) << char(223) << char(223);

    }
    else
        cout << "\a";

}
void Breakout::leftArrowkey()
{

    --cols;
    if (cols >= 21)//it stops strips to laft wall
    {
        gotoxy(cols + 5, rows);
        cout << " ";
        gotoxy(cols, rows);
        cout << char(223);
    }
    else
    {
        cout << "\a";
        cols++;
    }
}
void Breakout::rightArrowkey()
{
    ++cols;
    if (cols <= 54)   //it stops to right wall
    {
        gotoxy(cols - 1, rows);
        cout << " ";
        gotoxy(cols + 4, rows);
        cout << char(223);
    }
    else
    {
        cout << "\a";
        --cols;
    }
}
void Breakout::spacekey()
{
    //it pauses the game 
    gotoxy(25, 20);
    system("pause");
    gotoxy(25, 20);
    cout << "                                ";

}


bool Breakout::runGame()
{

    while (game)
    {
        if (_kbhit())
        {
            keysHandling();
        }


        if (shouldBallMove())
        {
            moveBall();
            
            
        }
        Sleep(30);
        

        
        if (ball_rows >= rows)   //game over
        {
            gameover();
        }


        if (score == 12 || score==46)
        {
            game = false;
            level ++;
            
           
            startGame();
        }
        else if (score >=82 &&level==3)
        {
            game = false;
            gotoxy(35, 12);
            cout << "Game End !!!";
            gotoxy(35, 14);
            cout << "Congrats !!!";
          
            setHighScore();

            goToHomeScreen();
            
        }
    }
    return false;
}
void Breakout::moveBall(){

    if (is_direction_up_right)
    {
        moveUpRight();
    }
    else if (is_direction_down_left)
    {
        moveDownLeft();
    }
    else if (is_direction_down_right)
    {
        moveDownRight();
    }
    else if (is_direction_up_left)
    {
        moveUpLeft();
    }

    else if (is_direction_up_left_2_increment)
    {
        moveUpLeftWith2Increment();
    }
    else if (is_direction_up_right_2_increment)
    {
        moveUpRightWith2Increment();
    }

    setDirection();

}
void Breakout::moveUpRight()
{

    gotoxy(ball_cols, ball_rows);
    cout << " ";
    gotoxy(++ball_cols, --ball_rows);
    cout << "O";


    is_coming_down_from_left = false;

    if (ballStrikesToBrick())
    {

        is_direction_up_right = false;
        is_direction_down_right = true;
    }
    else  if (ball_rows <= 5 && ball_cols >= 58)//bal is at top right corner 
    {
        is_direction_up_right = false;
        is_direction_down_left = true;
    }

    else if (ball_cols >= 58) //ball strikes to right wall
    {
        is_direction_up_right = false;
        is_direction_up_left = true;

    }
    else  if (ball_rows <= 5)   //bal sreikes to upper wall
    {

        is_direction_up_right = false;
        is_direction_down_right = true;

    }
     
}
void Breakout::moveUpLeft()
{

    gotoxy(ball_cols, ball_rows);
    cout << " ";
    gotoxy(--ball_cols, --ball_rows);
    cout << "O";

    is_coming_down_from_right = false;

    if (ballStrikesToBrick())
    {

        is_direction_up_left = false;
        is_direction_down_left = true;

    }
    else if (ball_rows <= 5 && ball_cols <= 21)    //bal is in uper left corner 
    {
        is_direction_up_left = false;
        is_direction_down_right = true;

    }
    else if (ball_rows <= 5)//ball strikes upper wall
    {
        is_direction_up_left = false;
        is_direction_down_left = true;

    }

    else if (ball_cols <= 21) //bal strikes left wall
    {
        is_direction_up_left = false;
        is_direction_up_right = true;

    }
     
}
void Breakout::moveDownLeft()
{

    gotoxy(ball_cols, ball_rows);
    cout << " ";
    gotoxy(--ball_cols, ++ball_rows);
    cout << "O";

    if (ballStrikesToBrick())
    {
        is_direction_down_left = false;
        is_direction_up_left = true;
    }

    else if (ball_rows == rows - 1 && ball_cols >= cols - 1 && ball_cols <= cols + 5) //bal hits the stripe
    {
        is_direction_down_left = false;
        is_coming_down_from_right = true;
    }
    else if (ball_cols <= 21)//ball strikes left wall
    {
        is_direction_down_left = false;
        is_direction_down_right = true;
    }

     
}
void Breakout::moveDownRight()
{

    gotoxy(ball_cols, ball_rows);
    cout << " ";

    gotoxy(++ball_cols, ++ball_rows);
    cout << "O";

    if (ballStrikesToBrick())
    {
        is_direction_down_right = false;
        is_direction_up_right = true;
    }
    else if (ball_rows == rows - 1 && ball_cols >= cols - 1 && ball_cols <= cols + 5) //bal hits the stripe
    {
        is_coming_down_from_left = true;
        is_direction_down_right = false;
    }
    else if (ball_cols >= 58)//bal strikes to left wall 
    {
        is_direction_down_right = false;
        is_direction_down_left = true;
    }


     
}
void Breakout::moveUpRightWith2Increment()
{

    gotoxy(ball_cols, ball_rows);
    cout << " ";
    gotoxy(ball_cols += 2, --ball_rows);
    cout << "O";
     

    if (ball_cols >= 57)
    {
        is_direction_up_right_2_increment = false;
        is_direction_up_left = true;
    }
}
void Breakout::moveUpLeftWith2Increment()
{

    gotoxy(ball_cols, ball_rows);
    cout << " ";
    gotoxy(ball_cols -= 2, --ball_rows);
    cout << "O";
     

    if (ball_cols <= 22)
    {
        is_direction_up_left_2_increment = false;
        is_direction_up_right = true;

    }

}
void Breakout::setDirection()
{

    if (((ball_cols == cols  && ball_cols <= 21)  //ball is at down left corner 
        || (ball_cols == cols + 3 || ball_cols == cols + 5)    //ball hits the stripe  on right side 
        || (is_coming_down_from_left &&ball_cols == cols + 2)) //bal hits in mid of stripe 
        && ball_rows == rows - 1)
    {
        tries++;
        scoreBoard();
        is_direction_up_right = true;
    }
    else if (((ball_cols == cols + 4 && ball_cols >=58) //ball is in right down corner 
        || (ball_cols == cols + 1 || ball_cols == cols - 1) //ball  hits  the stripe on left side 
        || (is_coming_down_from_right &&ball_cols == cols + 2)) // bal hits in mid of stripe 
        && (ball_rows == rows - 1))
    {
        tries++;
        scoreBoard();
        is_direction_up_left = true;
    }

    else if (ball_cols == cols + 4 && ball_rows == rows - 1)
    {
        tries++;
        scoreBoard();
        if (ball_cols >= 56)
            is_direction_up_left = true;
        else
            is_direction_up_right_2_increment = true;
    }
    else if (ball_cols == cols && ball_rows == rows - 1)
    {
        tries++;
        scoreBoard();
        if (ball_cols <= 22)
            is_direction_up_right = true;
        else
            is_direction_up_left_2_increment = true;
    }


}
bool Breakout::ballStrikesToBrick()
{
    row_index = ball_rows - 6;
    if (row_index < 4)
    {
        if (bricks[row_index][ball_cols - 22] == 1 && ball_rows == row_index + 6)//when bal hits to a brick
        {
            
            bricks[row_index][ball_cols - 22] = 0;  //index where bal hits 
            bricks[row_index][ball_cols - 21] = 0;  // next  index 
            bricks[row_index][ball_cols - 23] = 0; //pervious index

            gotoxy(ball_cols - 1, ball_rows);
            cout << "   ";

            score++;
            scoreBoard();
            return true;
        }
    }
    return false;
}

void Breakout::scoreBoard()
{

    gotoxy(65, 18);
    cout << "                          ";
    gotoxy(65, 18);
    cout << "Tries : " << tries;
    gotoxy(65, 20);
    cout << "                          ";
    gotoxy(65, 20);
    cout << "Scores : " << score;
}
void Breakout::setHighScore()
{
    fstream file;
    file.open("high score.txt", ios::in);
    if (!file)
    {
        highscore = 0;
    }
    else
    {
        file >> highscore;

    }
    file.close();

    if (highscore < score)
    {
        file.open("high score.txt", ios::out);
        highscore = score;
        file << highscore;
        file.close();
    }
}
void Breakout::gameover()
{
    game = false;
    gotoxy(35, 14);
    cout << "Game Over !!!";

    setHighScore();

    goToHomeScreen();

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
void Breakout::goToHomeScreen()
{
    

    gotoxy(22, 16);
    cout << "Press Backspace to Go to Home Screen";
    gotoxy(30, 18);
    cout << "Press Ecs to exit !!!!";
    ch = _getch();
    while (!(ch == 8||ch == 27))
    {
        cout << "\a";
        ch = _getch();
    }

    if (ch == 8)
    {
        
      
        score = 0;
        tries = 1;
        level = 1;

        system("cls");
        draw_board();
        home_screen();
    }
    else if (ch == 27)
    {
        gotoxy(25, 32);
        exit(1);
         }
}
void Breakout::resetBricks()
{
    for (int i = 0; i <4 ; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            bricks[i][j] = 0;
        }
    }
    
}