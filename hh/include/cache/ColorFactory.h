#ifndef COLORFACTORY_H
#define COLORFACTORY_H

#include "Color.h"
class ColorFactory
{
    public:
        ColorFactory();
        virtual ~ColorFactory();
        Color* createColor()
        {
            return new Color;
        }
};

#endif // COLORFACTORY_H
