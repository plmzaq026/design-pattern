#ifndef GLYPH_H
#define GLYPH_H
#include <bits/stdc++.h>
#include "Graphics.h"
using namespace std;
class Glyph
{
public:
    virtual Glyph* getChild(int i) = 0;
    virtual void display(Graphics* g) = 0;
};

#endif // GLYPH_H
