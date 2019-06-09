#ifndef PAGE_H
#define PAGE_H

#include "Glyph.h"

class Page
{
    public:
        Page();
        virtual ~Page();
    private:
        vector<Glyph * > rows;
};

#endif // PAGE_H
