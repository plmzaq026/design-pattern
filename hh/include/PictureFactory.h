#ifndef PICTUREFACTORY_H
#define PICTUREFACTORY_H
#include "Picture.h"

class PictureFactory
{
public:
    PictureFactory(){};
    virtual ~PictureFactory(){};
    Picture * createPicture(const string & str)
    {
        return new Picture(str);
    }
};

#endif // PICTUREFACTORY_H
