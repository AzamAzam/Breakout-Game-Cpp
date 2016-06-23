#include"breakout.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
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

void Breakout:: flag_variables_define()
{

    game = true; is_direction_up_right = true; is_direction_up_left = false; is_direction_down_left = false; is_direction_down_right = false;
    is_direction_up_right_2_increment = false; is_direction_up_left_2_increment = false; is_coming_down_from_right = false; is_coming_down_from_left = false;
}
void Breakout::startGame()
{
    system("cls");
    flag_variables_define();
    drawTiles();
    drawBoundary();
    drawStripeAndStriker();

    
    cols = 40, rows = i - 1;
    ball_rows = rows - 1, ball_cols = 42;
    

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
    gotoxy(40, i - 1);   // stripe
    for (int j = 1; j <= 5; j++)
    {
        setColor(3);
        cout << char(223);
    }
    gotoxy(42, i - 2);   // striker
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

    if (rows > 24&&(rows-ball_rows>2)) //stripe moves till bricks 
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
    //it pause the game 
    gotoxy(25, 20);
    system("pause");
    gotoxy(25, 20);
    cout << "                                ";
}
bool Breakout::runGame()
{
    game = true;
    while (game){
        
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
        scoreBoard();
        if (_kbhit())
        {
            keysHandling();
        }

        if (ball_rows >= rows)   //game over 
        {
            game = false;
        }


        if (score >= 12&&level==1)
        {
            game = false;
            level = 2;
            Sleep(5000);
           
            startGame();
        }
    }
    return false;
}
void Breakout::moveUpRight()
{

    gotoxy(ball_cols, ball_rows);
    cout << " ";
    gotoxy(++ball_cols, --ball_rows);
    cout << "O";
  

    is_coming_down_from_left = false;
    
    if (check_brick())
    {

        is_direction_up_right = false;
        is_direction_down_right = true;
    }
    else  if (ball_rows == 5 && ball_cols == 58)//bal is in top right corner 
    {
        is_direction_up_right = false;
        is_direction_down_left = true;
    }

    else if (ball_cols == 58) //ball strikes to right wall
    {
        is_direction_up_right = false;
        is_direction_up_left = true;

    }
    else  if (ball_rows == 5)   //bal sreikes to upper wall
    {

        is_direction_up_right = false;
        is_direction_down_right = true;

    }
    Sleep(sleep);
}
void Breakout::moveUpLeft()
{

    gotoxy(ball_cols, ball_rows);
    cout << " ";
    gotoxy(--ball_cols, --ball_rows);
    cout << "O";

    is_coming_down_from_right = false;
    if (check_brick())
    {

        is_direction_up_left = false;
        is_direction_down_left = true;

    }
    else if (ball_rows == 5 && ball_cols == 21)    //bal is in uper left corner 
    {
        is_direction_up_left = false;
        is_direction_down_right = true;

    }
    else if (ball_rows == 5)//ball strikes upper wall
    {
        is_direction_up_left = false;
        is_direction_down_left = true;

    }

    else if (ball_cols == 21) //bal strikes left wall
    {
        is_direction_up_left = false;
        is_direction_up_right = true;

    }
    Sleep(sleep);
}
void Breakout::moveDownLeft()
{

    gotoxy(ball_cols, ball_rows);
    cout << " ";
    gotoxy(--ball_cols, ++ball_rows);
    cout << "O";

    if (check_brick())
    {
        is_direction_down_left = false;
        is_direction_up_left = true;
    }

    else if (ball_rows == rows - 1 && ball_cols >= cols - 1 && ball_cols <= cols + 5) //bal hits the stripe
    {
        is_direction_down_left = false;
        is_coming_down_from_right = true;
    }
    else if (ball_cols == 21)//ball strikes left wall
    {
        is_direction_down_left = false;
        is_direction_down_right = true;
    }

    Sleep(sleep);
}
void Breakout::moveDownRight()
{

    gotoxy(ball_cols, ball_rows);
    cout << " ";

    gotoxy(++ball_cols, ++ball_rows);
    cout << "O";

    if (check_brick())
    {
        is_direction_down_right = false;
        is_direction_up_right = true;
    }
    else if (ball_rows == rows - 1 && ball_cols >= cols - 1 && ball_cols <= cols + 5) //bal hits the stripe
    {
        is_coming_down_from_left = true;
        is_direction_down_right = false;
    }
    else if (ball_cols == 58)//bal strikes to left wall 
    {
        is_direction_down_right = false;
        is_direction_down_left = true;
    }


    Sleep(sleep);
}
void Breakout::moveUpRightWith2Increment()
{

    gotoxy(ball_cols, ball_rows);
    cout << " ";
    gotoxy(ball_cols += 2, --ball_rows);
    cout << "O";
    Sleep(sleep);

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
    Sleep(sleep);

    if (ball_cols <= 22)
    {
        is_direction_up_left_2_increment = false;
        is_direction_up_right = true;

    }

}
void Breakout::setDirection()
{

    if (((ball_cols == cols  && ball_cols == 21)  //ball is in down left corner 
        || (ball_cols == cols + 3 || ball_cols == cols + 5)    //ball hits the stripe  on right side 
        || (is_coming_down_from_left &&ball_cols == cols + 2)) //bal hits in mid of stripe 
        && ball_rows == rows - 1)
    {
        tries++;
        is_direction_up_right = true;
    }
    else if (((ball_cols == cols + 4 && ball_cols == 58) //ball is in right down corner 
        || (ball_cols == cols + 1 || ball_cols == cols - 1) //ball  hits  the stripe on left side 
        || (is_coming_down_from_right &&ball_cols == cols + 2)) // bal hits in mid of stripe 
        && (ball_rows == rows - 1))
    {
        tries++;
        is_direction_up_left = true;
    }

    else if (ball_cols == cols + 4 && ball_rows == rows - 1)
    {
        tries++;
        if (ball_cols >= 58)
            is_direction_up_left = true;
        else
            is_direction_up_right_2_increment = true;
    }
    else if (ball_cols == cols && ball_rows == rows - 1)
    {
        tries++;
        if (ball_cols <= 21)
            is_direction_up_right = true;
        else
            is_direction_up_left_2_increment = true;
    }


}
bool Breakout::check_brick()
{
    row_index = ball_rows - 6;
    if (row_index < 4)
    {
        if (bricks[row_index][ball_cols - 22] == 1 && ball_rows == row_index + 6)//when bal hits to a brick
        {
            score++;
            bricks[row_index][ball_cols - 22] = 0;  //index where bal hits 
            bricks[row_index][ball_cols - 21] = 0;  // next  index 
            bricks[row_index][ball_cols - 23] = 0; //pervious index

            gotoxy(ball_cols - 1, ball_rows);
            cout << "   ";
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
    cout << "TRIES : " << tries;
    gotoxy(65, 20);
    cout << "                          ";
    gotoxy(65, 20);
    cout << "Scores : " << score;
}