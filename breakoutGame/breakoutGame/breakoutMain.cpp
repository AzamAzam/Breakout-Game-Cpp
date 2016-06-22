#include<iostream>
#include<conio.h>
#include <cstdlib>
#include<windows.h>

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
int main()
{
	system("mode con:cols=120 lines=35");

	int i, cols, rows, ball_cols, ball_rows, sleep = 300, score = 0, tries = 1;
	cout << "use left and right arrows to play this game";
	char ch;
	int bricks[75];
	gotoxy(20, 4);    // upper horizontal wall
	for (int i = 1; i <= 40; i++)
	{
		setColor(14);
		cout << char(220);
	}

	gotoxy(22, 6);	   // line 1 of tiles
	//	cout << " ";
	bricks[0] = 0;
	for (int i = 0; i <= 35; i++)
	{
		setColor(4);
		bricks[i] = 1;
		//	bricks[i + 1] = 0;

		cout << char(223);
	}


	//gotoxy(22, 7);    // line 2 of tiles
	//cout << " ";
	//for (int i = 1; i <= 12; i++)
	//{
	//	setColor(4);
	//	cout << char(223) << char(223) << " ";
	//}


	//gotoxy(22, 8);      // line 3 of tiles
	//cout << " ";
	//for (int i = 1; i <= 12; i++)
	//{
	//	setColor(4);
	//	cout << char(223) << char(223) << " ";
	//}



	for (i = 5; i <= 30; i++)    // vertical walls
	{
		setColor(14);
		gotoxy(20, i);
		cout << char(219);
		gotoxy(59, i);
		cout << char(219) << endl;
	}
	// i=31
	gotoxy(20, i);    // lower horizontal wall
	for (int j = 1; j <= 40; j++)
	{
		setColor(14);
		cout << char(223);
	}


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
	cols = 40, rows = i - 1;
	ball_rows = rows - 1, ball_cols = 42;
	ch = 'a';

	gotoxy(25, 20);
	system("pause");
	gotoxy(25, 20);
	cout << "                                ";
	//********************************************** ball movement **************************************************************************
	bool game = true, flag1 = true, flag2 = false, flag3 = false, flag4 = false, flag5 = false;
	bool flag6 = false, flag7 = false, flag8 = false;
	while (game)
	{

		//**********************************************  arrow keys handling starts  **************************************************************
		if (_kbhit())
		{

			ch = _getch();

			if (ch <= 0)
			{
				ch = _getch();
				if (ch == 77 || ch == 75 || ch == 72 || ch == 80)
				{
					if (ch == 77)  // right arrow key
					{
						++cols;
						if (cols <= 54 && cols >= 22)
						{
							gotoxy(cols - 1, rows);
							cout << " ";
							gotoxy(cols + 4, rows);
							cout << char(223);
						}
						else
						{
							cout << "\a";
							gotoxy(cols, rows);
							gotoxy(--cols, rows);
						}
					}
					else if (ch == 75)  // left arrow key
					{
						--cols;
						if (cols >= 21)
						{
							gotoxy(cols + 5, rows);
							cout << " ";
							gotoxy(cols, rows);
							cout << char(223);
						}
						else
						{
							cout << "\a";
							gotoxy(cols, rows);
							gotoxy(++cols, rows);
						}
					}
					else if (ch == 72) // up arrow key
					{

						if (rows > 10)
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
					else if (ch == 80) // down arrow key
					{

						if (rows < 30)
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
				}
				else
					cout << "\a";
			}
			else if (ch == 32)
			{
				gotoxy(25, 20);
				system("pause");
				gotoxy(25, 20);
				cout << "                                ";
			}
			else
				cout << "\a";
		}
		//**********************************************  arrow keys handling end  **************************************************************		

		//*************************************************ball movement *********************************************************
		if (flag1)    // first time     &  down to right up 
		{
			gotoxy(ball_cols, ball_rows);
			cout << " ";
			gotoxy(++ball_cols, --ball_rows);
			cout << "O";
			Sleep(sleep);
			flag8 = false;
			if (bricks[ball_cols - 22] == 1 && ball_rows == 6)
			{
				score++;
				bricks[ball_cols - 22] = 0;
				flag1 = false;
				flag4 = true;

			}
			else if (ball_rows == 5 && ball_cols == 58)
			{
				flag1 = false;
				flag3 = true;
			}

			else if (ball_cols == 58)
			{
				flag1 = false;
				flag2 = true;

			}
			else  if (ball_rows == 5)
			{

				flag1 = false;
				flag4 = true;

			}
		}
		else if (flag2)          // right to up & down to right
		{
			gotoxy(ball_cols, ball_rows);
			cout << " ";
			gotoxy(--ball_cols, --ball_rows);
			cout << "O";
			Sleep(sleep);
			flag7 = false;
			if (bricks[ball_cols - 22] == 1 && ball_rows == 6)
			{
				score++;
				bricks[ball_cols - 22] = 0;

				flag2 = false;
				flag3 = true;

			}
			else if (ball_rows == 5 && ball_cols == 21)
			{
				flag2 = false;
				flag6 = true;

			}
			else if (ball_rows == 5)
			{
				flag2 = false;
				flag3 = true;

			}

			else if (ball_cols == 21)
			{
				flag2 = false;
				flag1 = true;

			}

		}
		else if (flag3)   // from up to left & down 
		{
			gotoxy(ball_cols, ball_rows);
			cout << " ";
			gotoxy(--ball_cols, ++ball_rows);
			cout << "O";
			Sleep(sleep);
			if (bricks[ball_cols - 22] == 1 && ball_rows == 6)
			{
				score++;
				bricks[ball_cols - 22] = 0;

				flag3 = false;
				flag2 = true;
			}

			else if (ball_rows == rows - 1 && ball_cols >= cols - 1 && ball_cols <= cols + 5)
			{
				flag7 = true;
				flag3 = false;
			}
			else if (ball_cols == 21)
			{
				flag3 = false;
				flag4 = true;
			}


		}


		else if (flag4)               // from up to right down  & left to down 
		{

			gotoxy(ball_cols, ball_rows);
			cout << " ";

			gotoxy(++ball_cols, ++ball_rows);
			cout << "O";
			Sleep(sleep);
			if (bricks[ball_cols - 22] == 1 && ball_rows == 6)
			{
				score++;
				bricks[ball_cols - 22] = 0;

				flag4 = false;
				flag1 = true;
			}
			else if (ball_cols == 58)
			{
				flag4 = false;
				flag3 = true;
			}

			else if (ball_rows == rows - 1 && ball_cols >= cols - 1 && ball_cols <= cols + 5)
			{
				flag8 = true;
				flag4 = false;
			}
		}
		else if (flag5)    //down to right with 2 increment 
		{
			gotoxy(ball_cols, ball_rows);
			cout << " ";
			gotoxy(ball_cols += 2, --ball_rows);
			cout << "O";
			Sleep(sleep);

			if (ball_cols >= 57)
			{
				flag5 = false;
				flag2 = true;
			}
		}

		else 	if (flag6)    // from down to left up
		{
			gotoxy(ball_cols, ball_rows);
			cout << " ";
			gotoxy(ball_cols -= 2, --ball_rows);
			cout << "O";
			Sleep(sleep);

			if (ball_cols <= 22)
			{
				flag6 = false;
				flag1 = true;

			}


		}

		if (ball_cols == cols && ball_rows == rows - 1 && ball_cols == 21)
		{
			tries++;
			flag1 = true;
		}
		else if ((ball_cols == cols + 1 || ball_cols == cols - 1) && ball_rows == rows - 1)
		{
			tries++;
			flag2 = true;
		}
		else  if (ball_cols == cols + 4 && ball_rows == rows - 1 && ball_cols == 58)
		{
			tries++;
			flag2 = true;
		}

		else  if ((ball_cols == cols + 3 || ball_cols == cols + 5) && ball_rows == rows - 1)
		{
			tries++;
			flag1 = true;
		}
		else if (ball_cols == cols + 4 && ball_rows == rows - 1)
		{
			tries++;
			flag5 = true;
		}
		else if (ball_cols == cols && ball_rows == rows - 1)
		{
			tries++;
			flag6 = true;
		}
		else if (flag7 &&ball_cols == cols + 2 && ball_rows == rows - 1)
		{
			tries++;
			flag2 = true;
		}
		else if (flag8 &&ball_cols == cols + 2 && ball_rows == rows - 1)
		{
			tries++;
			flag1 = true;
		}
		if (ball_rows == rows)
		{
			game = false;
		}

		gotoxy(65, 18);
		cout << "TRIES : " << tries;
		gotoxy(65, 20);
		cout << "Scores : " << score;
	}
	//******************************************* end of ball movement *************************************************************************
	gotoxy(18, 34);
	cout << endl << endl;


}
