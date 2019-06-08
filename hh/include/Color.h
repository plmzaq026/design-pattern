#ifndef COLOR_H
#define COLOR_H
#include <cdk.h>
#include <bits/stdc++.h>
using namespace std;
class Color
{
    public:
        Color(WINDOW * win)
        {
            this->win = win;
            initscr();
            if(has_colors() == false)
            {
                printw("DO NOT SUPPORT COLOR\n");
            }
            start_color();
            init_pair(1,COLOR_RED,COLOR_BLACK);
            init_pair(2,COLOR_BLUE,COLOR_BLACK);
            init_pair(3,COLOR_WHITE,COLOR_RED);
            init_pair(4,COLOR_WHITE,COLOR_BLUE);
            init_pair(5,COLOR_WHITE,COLOR_BLACK);

        };
        virtual ~Color()
        {
            getch();
            endwin();
        };
        void RED()
        {
            attron(COLOR_PAIR(1));
        }

        void BLUE()
        {
            attron(COLOR_PAIR(2));
        }
    private:
        WINDOW * win;
};

#endif // COLOR_H
