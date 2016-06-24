#include <cstdlib>
#include "breakout.h"




int main()
{
	system("mode con:cols=120 lines=35");


    Menu m;

    m.cout_breakout1();
    m.name_and_rol_no();
    if (m.loading())
        m.home_screen();
    else
        m.my_exit();
    
   // Breakout b;
   // b.startGame();
}
