#include "TestFile.h"
#include <cdk.h>

TestFile::TestFile()
{
    win = initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, true);
}

TestFile::~TestFile()
{
    getch();
    endwin();
}
void TestFile::testGraphics()
{
    Graphics *gc = new Graphics(win);
    //gc->draw_Hline(100,100,10,10);
    gc->drawRectangle(40,20);
    while(1)
    {
        char ch = getch();
        if(ch == 27)
        {
            ch = getch();
            if(ch == 'r')
            {
                gc->setForeColor(1);
            }else
            if(ch == 'b')
            {
                gc->setForeColor(2);
            }else
            if(ch == 'R')
            {
                gc->setBackColor(3);
            }else
            if(ch == 'B')
            {
                gc->setBackColor(4);
            }else
            if(ch == '1')
            {
                gc->setFont(1);
            }else
            if(ch == '2')
            {
                gc->setFont(2);
            }else break;
        }
        gc->draw_char(ch);
    }
    gc->draw_string(" ko no dio da!");
}


void TestFile::testFrame(string fn)
{
    Frame ed = (fn != "")?Frame(win,fn):Frame(win);
    while(ed.getMode() != 'x')
    {
        if(ed.upstatus)
            ed.updateStatus();
        ed.printStatusLine();
        ed.printBuff();
        int input = getch();
        ed.handleInput(input);
    }

}


