#ifndef CHARFACTORY_H
#define CHARFACTORY_H

#include "Char.h"

class CharFactory
{
    public:
        Char* createChar(char c)
        {
            return new Char(c);
        }
};

#endif // CHARFACTORY_H
