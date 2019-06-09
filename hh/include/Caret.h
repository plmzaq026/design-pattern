#ifndef CARET_H
#define CARET_H

#include <ncurses.h>
#include "Buffer.h"
class Caret
{
    public:
        Caret(WINDOW * win)
        {
            this->win = win;
            this->buff = new Buffer;
        }

        void moveLeft()
        {
            if(x-1 >= 0)
            {
                x--;
                move(y, x);
            }
        }

        void moveRight()
        {
            if(x+1 < COLS && x+1 <= buff->lines[y].length())
            {
                x++;
                move(y, x);
            }
        }

        void moveUp()
        {
            if(y-1 >= 0)
            {
                y--;
            }
            else if(y-1 < 0 && lowerbound > 0)
            {
                lowerbound--;
            }
            if(x >= buff->lines[y].length())
                x = buff->lines[y].length();
            move(y, x);
        }

        void moveDown()
        {
            if(y+1 < LINES-1 && y+1 < buff->lines.size())
            {
                y++;
            }
            else if(lowerbound+y < buff->lines.size())
            {
                raiseflag = true;
                lowerbound++;
            }
            if(x >= buff->lines[y].length())
                x = buff->lines[y].length();
            move(y, x);
        }


        void deleteLine()
        {
            buff->removeLine(y);
        }
        void deleteLine(int i)
        {
            buff->removeLine(i);
        }
        int x,y;
        int lowerbound;
        bool raiseflag;
        Buffer * buff;
    private:
        WINDOW * win;

};

#endif // CARET_H
