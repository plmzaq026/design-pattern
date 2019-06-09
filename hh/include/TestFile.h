#ifndef TESTFILE_H
#define TESTFILE_H

#include"Graphics.h"

#include "Row.h"
#include "PictureFactory.h"
#include "CharFactory.h"

#include "Font.h"
#include "ColorFactory.h"


#include "Frame.h"


class TestFile
{
    public:
        TestFile();
        virtual ~TestFile();
        void testGraphics();
        void testFrame(string);
    private:
        WINDOW * win;
};

#endif // TESTFILE_H
