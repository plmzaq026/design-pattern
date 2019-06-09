#ifndef PARAGRAPH_H
#define PARAGRAPH_H

#include "Glyph.h"
#include "StringFormat.h"

class Paragraph
{
private:
    vector<Glyph *> rows;
    bool formatted;
    StringFormat * sf;
public:
    Paragraph()
    {
        formatted = false;
    };
};

#endif // PARAGRAPH_H
