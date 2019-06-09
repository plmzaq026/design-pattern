#ifndef FONT_H
#define FONT_H



#include <cdk.h>
#include <bits/stdc++.h>
using namespace std;
class Font
{
    public:
    //id = 0,1,2
        Font(WINDOW * win,int id = 0)
        {
            this->win = win;
            this->id = (0 <= id && id <= 3)?id:0;
            initscr();

        };
        virtual ~Font()
        {
            getch();
            endwin();
        };
        void DEFAULT()
        {
            attron(A_NORMAL);
        };
        void UNDERLINE()
        {
            attron(A_UNDERLINE);
        };
        void BOLD()
        {
            attron(A_BOLD);
        };
    private:
        WINDOW * win;
        int id;
};

#endif // FONT_H
