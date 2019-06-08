#include "TestFile.h"

TestFile::TestFile()
{
    win = initscr();
}

TestFile::~TestFile()
{
    getch();
    endwin();

}

void TestFile::testGraphics()
{
    refresh();
    Graphics *gc = new Graphics(win);
    //gc->draw_Hline(100,100,10,10);
    gc->drawRectangle(40,20);
    noecho();
    while(1)
    {
        char ch = getch();
        if(ch == 27)
        {
            ch = getch();
            if(ch == 'r')
            {
                gc->setForeColor(1);
                noecho();
            }else
            if(ch == 'b')
            {
                gc->setForeColor(2);
                noecho();
            }else
            break;
        }
        gc->draw_char(ch);
    }
    gc->draw_string(" ko no dio da!");

}
