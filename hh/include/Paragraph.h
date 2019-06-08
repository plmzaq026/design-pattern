#ifndef PARAGRAPH_H
#define PARAGRAPH_H

#include "CharFactory.h"
#include "PictureFactory.h"
#include "Row.h"

class Paragraph
{
private:
    vector<Glyph *> glyphs;
    vector<Row *> rows;
    bool formatted;
public:
    Paragraph()
    {

    };


};

#endif // PARAGRAPH_H
