#ifndef COLOR_H
#define COLOR_H
#include <cdk.h>
#include <bits/stdc++.h>
using namespace std;
class Color
{
    public:
    //id = 0,1,2,3,4
        Color(WINDOW * win,int id = 0)
        {
            this->win = win;
            this->id = (0 <= id && id <= 4)?id:0;
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
            init_pair(0,COLOR_WHITE,COLOR_BLACK);

        };
        virtual ~Color()
        {
            getch();
            endwin();
        };
        void F_RED()
        {
            attron(COLOR_PAIR(1));
        }

        void F_BLUE()
        {
            attron(COLOR_PAIR(2));
        }

        void B_RED()
        {
            attron(COLOR_PAIR(3));
        }
        void B_BLUE()
        {
            attron(COLOR_PAIR(4));
        }
        void DEFAULT()
        {
            attron(COLOR_PAIR(0));
        }
    private:
        WINDOW * win;
        int id;
};

#endif // COLOR_H
