#ifndef CHAR_H
#define CHAR_H

#include "Glyph.h"


class Char:public Glyph
{
private:
    char c;
public:
    Char(char ch)
    {
        c = ch;
    };
    Char(Char& ch)
    {
        c = ch.getValue();
    }
    char getValue()
    {
        return c;
    }
    bool equals(Char & ch)
    {
        return ch.c == this->c;
    }
    void display(Graphics* g)
    {
        if(c == '\t')
            return;
        g->draw_char(c);
    }
    Glyph* getChild(int i)
    {
        return NULL;
    };
};

#endif // CHAR_H
