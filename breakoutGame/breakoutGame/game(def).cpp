
#include "breakout.h"
#include<fstream>


void Menu::cout_breakout1()
{
    int i;
    for (i = 5; i < 14; i++)
    {
        //  B
        setColor(11);
        gotoxy(4, i);
        Sleep(100);
        if (i == 5 || i == 13)
            cout << "B B B B";
        else if (i == 6 || i == 7 || i == 11 || i == 12)
            cout << "B      B";
        else if (i == 8 || i == 10)
            cout << "B     B";
        else
            cout << "B B B";

        //  R
        setColor(10);
        gotoxy(14, i);
        if (i == 5)
            cout << "R R R R";
        else if (i == 6 || i == 8 || i == 11)
            cout << "R      R";
        else if (i == 7 || i == 12)
            cout << "R       R";
        else if (i == 9)
            cout << "R R R";
        else if (i == 10)
            cout << "R     R";
        else
            cout << "R        R";

        // E
        setColor(12);
        gotoxy(26, i);
        Sleep(100);
        if (i == 5 || i == 9 || i == 13)
            cout << "E E E E";
        else
            cout << "E       ";

        // O
        setColor(15);
        gotoxy(67, i);
        Sleep(100);
        if (i == 5 || i == 13)
            cout << "  O O O O ";
        else
            cout << "O         O";

        // U
        setColor(10);
        gotoxy(80, i);
        Sleep(100);
        if (i == 13)
            cout << "  U U U U ";
        else
            cout << "U         U";

        // T
        setColor(11);
        gotoxy(93, i);
        Sleep(100);
        if (i == 5)
            cout << "T T T T T T T";
        else
            cout << "      T";
    }
    //   A
    setColor(9);
    gotoxy(34, 5);
    Sleep(100);
    cout << "         A";
    gotoxy(34, 6);
    Sleep(100);
    cout << "        A A";
    gotoxy(34, 7);
    Sleep(100);
    cout << "       A   A";
    gotoxy(34, 8);
    Sleep(100);
    cout << "      A     A";
    gotoxy(34, 9);
    Sleep(100);
    cout << "     A A A A A";
    gotoxy(34, 10);
    Sleep(100);
    cout << "    A         A";
    gotoxy(34, 11);
    Sleep(100);
    cout << "   A           A";
    gotoxy(34, 12);
    Sleep(100);
    cout << "  A             A";
    gotoxy(34, 13);
    Sleep(100);
    cout << " A               A";

    //   K
    setColor(14);
    gotoxy(54, 5);
    Sleep(100);
    cout << "K        K";
    gotoxy(54, 6);
    Sleep(100);
    cout << "K      K";
    gotoxy(54, 7);
    Sleep(100);
    cout << "K    K";
    gotoxy(54, 8);
    Sleep(100);
    cout << "K  K";
    gotoxy(54, 9);
    Sleep(100);
    cout << "K K";
    gotoxy(54, 10);
    Sleep(100);
    cout << "K  K";
    gotoxy(54, 11);
    Sleep(100);
    cout << "K    K";
    gotoxy(54, 12);
    Sleep(100);
    cout << "K      K";
    gotoxy(54, 13);
    Sleep(100);
    cout << "K        K";
    cout << endl;
}

void Menu::cout_breakout2(int num)
{
    //int i;
    setColor(num);     //   B
    gotoxy(4, 5);
    cout << "B B B B";
    gotoxy(4, 6);
    cout << "B      B";
    gotoxy(4, 7);
    cout << "B      B";
    gotoxy(4, 8);
    cout << "B     B";
    gotoxy(4, 9);
    cout << "B B B";
    gotoxy(4, 10);
    cout << "B     B";
    gotoxy(4, 11);
    cout << "B      B";
    gotoxy(4, 12);
    cout << "B      B";
    gotoxy(4, 13);
    cout << "B B B B";

    setColor(num);        //   R
    gotoxy(14, 5);
    cout << "R R R R";
    gotoxy(14, 6);
    cout << "R      R";
    gotoxy(14, 7);
    cout << "R       R";
    gotoxy(14, 8);
    cout << "R      R";
    gotoxy(14, 9);
    cout << "R R R";
    gotoxy(14, 10);
    cout << "R     R";
    gotoxy(14, 11);
    cout << "R      R";
    gotoxy(14, 12);
    cout << "R       R";
    gotoxy(14, 13);
    cout << "R        R";

    setColor(num);    //   E
    gotoxy(26, 5);
    cout << "E E E E";
    gotoxy(26, 6);
    cout << "E       ";
    gotoxy(26, 7);
    cout << "E       ";
    gotoxy(26, 8);
    cout << "E       ";
    gotoxy(26, 9);
    cout << "E E E E";
    gotoxy(26, 10);
    cout << "E       ";
    gotoxy(26, 11);
    cout << "E       ";
    gotoxy(26, 12);
    cout << "E       ";
    gotoxy(26, 13);
    cout << "E E E E";




    setColor(num);      //   A
    gotoxy(34, 5);
    cout << "         A";
    gotoxy(34, 6);
    cout << "        A A";
    gotoxy(34, 7);
    cout << "       A   A";
    gotoxy(34, 8);
    cout << "      A     A";
    gotoxy(34, 9);
    cout << "     A A A A A";
    gotoxy(34, 10);
    cout << "    A         A";
    gotoxy(34, 11);
    cout << "   A           A";
    gotoxy(34, 12);
    Sleep(100);
    cout << "  A             A";
    gotoxy(34, 13);

    cout << " A               A";


    setColor(num);       //    K
    gotoxy(54, 5);
    cout << "K        K";
    gotoxy(54, 6);
    cout << "K      K";
    gotoxy(54, 7);
    cout << "K    K";
    gotoxy(54, 8);
    cout << "K  K";
    gotoxy(54, 9);
    cout << "K K";
    gotoxy(54, 10);
    cout << "K  K";
    gotoxy(54, 11);
    cout << "K    K";
    gotoxy(54, 12);
    cout << "K      K";
    gotoxy(54, 13);
    cout << "K        K";




    setColor(num);          //   O
    gotoxy(67, 5);
    cout << "  O O O O ";
    gotoxy(67, 6);
    cout << "O         O";
    gotoxy(67, 7);
    cout << "O         O";
    gotoxy(67, 8);
    cout << "O         O";
    gotoxy(67, 9);
    cout << "O         O";
    gotoxy(67, 10);
    cout << "O         O";
    gotoxy(67, 11);
    cout << "O         O";
    gotoxy(67, 12);
    cout << "O         O";
    gotoxy(67, 13);
    cout << "  O O O O ";



    setColor(num);     //   U
    gotoxy(80, 5);
    cout << "U         U";
    gotoxy(80, 6);
    cout << "U         U";
    gotoxy(80, 7);
    cout << "U         U";
    gotoxy(80, 8);
    cout << "U         U";
    gotoxy(80, 9);
    cout << "U         U";
    gotoxy(80, 10);
    cout << "U         U";
    gotoxy(80, 11);
    cout << "U         U";
    gotoxy(80, 12);
    cout << "U         U";
    gotoxy(80, 13);
    cout << "  U U U U ";



    setColor(num);        //   T
    gotoxy(93, 5);
    cout << "T T T T T T T";
    gotoxy(93, 6);
    cout << "      T";
    gotoxy(93, 7);
    cout << "      T";
    gotoxy(93, 8);
    cout << "      T";
    gotoxy(93, 9);
    cout << "      T";
    gotoxy(93, 10);
    cout << "      T";
    gotoxy(93, 11);
    cout << "      T";
    gotoxy(93, 12);
    cout << "      T";
    gotoxy(93, 13);
    cout << "      T";


    cout << endl;

}

void Menu::name_and_rol_no()
{
    gotoxy(46, 16);
    setColor(11);
    cout << "By";
    //  Names
    gotoxy(30, 18);
    setColor(10);
    cout << "N"; Sleep(80); cout << "A"; Sleep(80); cout << "M"; Sleep(80); cout << "A"; Sleep(80); cout << "N";
    Sleep(80); cout << " A"; Sleep(80); cout << "L"; Sleep(80); cout << "I"; Sleep(80); cout << " K"; Sleep(80);
    cout << "H"; Sleep(80); cout << "A"; Sleep(80); cout << "N"; Sleep(80); cout << "   &   "; Sleep(80); cout << "M";
    Sleep(80); cout << "U"; Sleep(80); cout << "H"; Sleep(80); cout << "A"; Sleep(80); cout << "M"; Sleep(80);
    cout << "M"; Sleep(80); cout << "A"; Sleep(80); cout << "D"; Sleep(80); cout << " A"; Sleep(80); cout << "Z";
    Sleep(80); cout << "A"; Sleep(80); cout << "M";

    // Roll no's
    gotoxy(30, 19);
    cout << "B"; Sleep(80); cout << "C"; Sleep(80); cout << "S"; Sleep(80); cout << "F"; Sleep(80); cout << "1";
    Sleep(80); cout << "5"; Sleep(80); cout << "M"; Sleep(80); cout << "0"; Sleep(80); cout << "2"; Sleep(80);
    cout << "2"; Sleep(80); cout << "           B"; Sleep(80); cout << "C"; Sleep(80); cout << "S"; Sleep(80);
    cout << "F"; Sleep(80); cout << "1"; Sleep(80); cout << "5"; Sleep(80); cout << "M"; Sleep(80); cout << "0"; Sleep(80);
    cout << "1"; Sleep(80); cout << "7";
}

bool Menu::loading()
{
    char ch;
    gotoxy(20, 23);   // Loading
    setColor(7);
    cout << "Loading...  ";
    gotoxy(5, 24);
    for (int i = 5; i <= 105; i++)
    {
        cout << "|";
        gotoxy(37, 23);
        cout << i - 5 << " %";
        gotoxy(i, 24);
        Sleep(50);

    }
    gotoxy(30, 26);
    cout << "Press any key to continue ....";
    gotoxy(30, 27);
    cout << "Press Esc to Exit";
    bool flag = true;
    int num = 9;
    while (flag)
    {

        if (_kbhit())
        {
            ch = _getch();
            flag = false;
        }

        else
        {
            Sleep(700);
            gotoxy(30, 18);
            setColor(num);
            cout << "NAMAN ALI KHAN   &   MUHAMMAD AZAM";
            gotoxy(30, 19);
            num++;
            if (num > 15)
                num = 9;
            setColor(num);
            cout << "BCSF15M022           BCSF15M017    ";
            num++;
            if (num > 15)
                num = 9;
            cout_breakout2(num);
            //gotoxy(47, 27);
        }
    }
    if (ch == 27)
        return false;
    else
        return true;
}

void Menu::draw_board()
{
    int i = 30, j;
    gotoxy(i, 5);
    setColor(14);
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *";  // above line of asterics
    cout << endl;

    for (j = 5; j <= 20; j++)   // vertical  lines   of  asterics
    {
        gotoxy(i, j);
        cout << "*";
        gotoxy(84, j);
        cout << "*";
    }
    gotoxy(i, j - 1);
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * *"; // lower line of asterics
}

void Menu::home_screen()
{
    gotoxy(50, 9);
    setColor(11);
    cout << "Play Game";
    gotoxy(50, 12);
    cout << "High Score";
    gotoxy(50, 15);
    cout << "Help";
}

void Menu::select_option()
{
    Breakout Game;
    char ch;
    int line = 0;
    bool  highlight_play_game = true, highlight_high_score = false, highlight_help = false;
    while (true)
    {
        if (_kbhit())
        {
            ch = _getch();
            if (ch == 9)
            {
                if (highlight_play_game)
                {
                    gotoxy(50, 14);
                    setColor(11);
                    cout << "              ";
                    gotoxy(50, 15);
                    cout << "Help";
                    gotoxy(50, 16);
                    cout << "              ";
                    gotoxy(50, 8);
                    setColor(4);
                    draw_line();
                    gotoxy(50, 9);
                    cout << "Play Game";
                    gotoxy(50, 10);
                    draw_line();
                    line = 10;
                    highlight_play_game = false;
                    highlight_high_score = true;
                }
                else if (highlight_high_score)
                {
                    gotoxy(50, 8);
                    setColor(11);
                    cout << "              ";
                    gotoxy(50, 9);
                    cout << "Play Game";
                    gotoxy(50, 10);
                    cout << "              ";
                    gotoxy(50, 11);
                    setColor(4);
                    draw_line();
                    gotoxy(50, 12);
                    cout << "High Score";
                    gotoxy(50, 13);
                    draw_line();
                    line = 13;
                    highlight_high_score = false;
                    highlight_help = true;
                }
                else if (highlight_help)
                {
                    gotoxy(50, 11);
                    setColor(11);
                    cout << "              ";
                    gotoxy(50, 12);
                    cout << "High Score";
                    gotoxy(50, 13);
                    cout << "              ";
                    gotoxy(50, 14);
                    setColor(4);
                    draw_line();
                    gotoxy(50, 15);
                    cout << "Help";
                    gotoxy(50, 16);
                    draw_line();
                    line = 16;
                    highlight_help = false;
                    highlight_play_game = true;
                }
            }
            else if ((ch == 13 || ch == 10) && line >= 10)
            {

                if (line == 10)
                {
                   
                   
                    Game.startGame();
                    
                }
                else if (line == 13)
                    high_score();
                else if (line == 16)
                    help();
                else
                    cout << "\a";
                line = 9;
                highlight_play_game=true;
                
            }
            else
                cout << "\a";
            
     
        }
    }
}

void Menu::high_score()
{
    char choice;
    fstream file;
    file.open("high score.txt", ios::in);
    if (!file)
        High_score = 0;
    else 
    file>>High_score;
    file.close();

    system("cls");
    draw_board();
    gotoxy(50, 13);
    setColor(7);
    cout << "High Score : " << High_score;
    gotoxy(40, 25);
    cout << "Press any key to continue ....";
    gotoxy(40, 26);
    cout << "press Esc to Exit....";
    choice = _getch();
    if (choice == 27)
    {
        gotoxy(50, 26);
        exit(1);
    }
    else
    {
        system("cls");
        draw_board();
        home_screen();
    }
}

void Menu::help()
{
    char choice;
    system("cls");
    draw_board();
    gotoxy(40, 8);
    setColor(7);
    cout << "You can move stripe using Arrow Keys";
    gotoxy(40, 10);
    cout << "1 : Left Arrow Key to move left";
    gotoxy(40, 12);
    cout << "2 : Right Arrow Key to move right";
    gotoxy(40, 14);
    cout << "3 : Up Arrow Key to move up";
    gotoxy(40, 16);
    cout << "4 : Down Arrow Key to move down";
    gotoxy(40, 25);
    cout << "Press any key to continue ....";
    gotoxy(40, 26);
    cout << "press Esc to Exit....";
    choice = _getch();
    if (choice == 27)
    {
        gotoxy(50, 26);
        exit(1);
    }
    else
    {
        system("cls");
        draw_board();
        home_screen();
    }
}




