#ifndef COLORFACTORY_H
#define COLORFACTORY_H

#include "Color.h"
class ColorFactory
{
    public:
        Color * createColor(WINDOW * win, int id)
        {
            return new Color(win,id);
        }
};

#endif // COLORFACTORY_H
