#include <cstdlib>
#include "breakout.h"




int main()
{
	system("mode con:cols=120 lines=35");


    Menu m;

    m.cout_breakout1();
    m.name_and_rol_no();
    if (m.loading())
    {
        system("cls");
        m.draw_board();
        m.home_screen();
        m.select_option();
    }
    else
    {
        system("cls");
        gotoxy(55, 17);
        cout << "Good Bye !!!";
        exit(1);
    }

    gotoxy(35, 32);
}
