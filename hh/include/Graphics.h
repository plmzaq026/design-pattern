#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <ncurses.h>
#include <cdk.h>
#include <bits/stdc++.h>

#include "FontFactory.h"
#include "ColorFactory.h"
using namespace std;
class Graphics
{
    public:
        Graphics(WINDOW * win)
        {
            this->win = win;
            current_x = 0;
            current_y = 0;
        };
        WINDOW * getWindow()
        {
            return this->win;
        }
        virtual ~Graphics()
        {
            delwin(win);
        };
        void draw_Hline(int x1,int y1,int x2,int y2)
        {
            drawLine(win,x1,y1,x2,y2,ACS_HLINE);
        }
        void draw_Vline(int x1,int y1,int x2,int y2)
        {
            drawLine(win,x1,y1,x2,y2,ACS_VLINE);
        }
        void drawRectangle(int width, int height)
        {
            current_x = 1;
            current_y = 1;

            getyx(win,current_x,current_y);
            draw_Vline(current_x,current_y,current_x ,current_y+height);
            current_y = current_y + height;

            draw_Hline(current_x,current_y,current_x + width,current_y);
            current_x = current_x + width;

            draw_Vline(current_x,current_y - height,current_x,current_y);
            current_y = current_y - height;

            draw_Hline(current_x - width,current_y,current_x,current_y);
            current_x = current_x - width;

        }
        void draw_char(char c)
        {
            char * ch = new char(c);
            getyx(win,current_y,current_x);
            writeChar(win,current_x,current_y,ch,HORIZONTAL,0,1);
        }
        void draw_string(string s)
        {
            char * ch = new char [s.length()];
            for(int i =0 ;i < s.length();i ++)
                ch[i] = s[i];
            getyx(win,current_y,current_x);
            writeChar(win,current_x,current_y,ch,HORIZONTAL,0,s.length());
        }
        int getCharWidth()
        {
            return 1;
        }
        int getCharHeight()
        {
            return 1;
        }
        void setFont(int index)
        {
            FontFactory * ff = new FontFactory;
            Font * my_font = ff->createFont(win,(index == 1 || index == 2)?index:0);
            if(index == 1)
                my_font->BOLD();
            else
            if(index == 2)
                my_font->UNDERLINE();
            else
                my_font->DEFAULT();
        }
        void setForeColor(int index)
        {
            ColorFactory * cf = new ColorFactory;
            Color * my_color = cf->createColor(win,(index == 1 || index == 2)?index:0);
            if(index == 1)
                my_color->F_RED();
            else
            if(index == 2)
                my_color->F_BLUE();
            else
                my_color->DEFAULT();
        }
        void setBackColor(int index)
        {
            ColorFactory * cf = new ColorFactory;
            Color * my_color = cf->createColor(win,(index == 3 || index == 4)?index:0);
            if(index == 3)
                my_color->F_RED();
            else
            if(index == 4)
                my_color->F_BLUE();
            else
                my_color->DEFAULT();
        }
    private:
        WINDOW * win;
        int current_x;
        int current_y;
};

#endif // GRAPHICS_H
