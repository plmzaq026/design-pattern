#ifndef FONTFACTORY_H
#define FONTFACTORY_H


#include "Font.h"
class FontFactory
{
    public:
        Font * createFont(WINDOW * win, int id)
        {
            return new Font(win,id);
        }
};
#endif // FONTFACTORY_H
