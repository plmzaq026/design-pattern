#include <bits/stdc++.h>
#include <ncurses>
using namespace std;


class Glyph
{
public:
    virtual void Draw(WINDOW *);
    virtual void Bounds(int& height,int& width,int& y, int& x);
    virtual bool Intersects();
    virtual void Insert(Glyph *,int);
    virtual void Remove(Glyph *);
    virtual Glyph* Child(int);
    virtual Glyph* Parent();
};

class Rectangle:public Glyph
{
private:
    char c;
    int height;
    int width;
    int starty;
    int startx;
public:
    void Draw(WINDOW* w)
    {
        w = newwin(height,width,starty,startx);
        box(w,0,0);
        wrefresh(w);
    };
    void Bounds(int& height,int& width,int& starty, int& startx)
    {
        height = this->height;
        width = this->width;
        starty = this->starty;
        startx = this->startx;
    };
    bool Intersects()
    {
        int y,x;
        getyx(stdscr,y,x);
        if(starty <= y && y <= starty + height
           && startx <= x && x <= startx + width)
            return true;
        return false;
    };
    void Insert(Glyph * g,int index)
    {
        g->
    }

};

int main(void)
{

    return 0;
}
