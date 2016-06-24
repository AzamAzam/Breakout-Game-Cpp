#ifndef MENU_H
#define MENU_H
#include<iostream>
#include<conio.h>
using namespace std;
#include<Windows.h>

class Menu
{
private:
	int i,High_score;
	char ch;
	
public:
	void draw_line()
	{
		cout << "______________";
	}
	
	void cout_breakout1();
	void cout_breakout2(int);
	void name_and_rol_no();
	bool loading();
	void draw_board();
	void home_screen();
	void select_option();

	void high_score();
	void help();
    void my_exit();
};
#endif