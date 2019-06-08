#ifndef TESTFILE_H
#define TESTFILE_H

#include"Graphics.h"

#include "Row.h"
#include "PictureFactory.h"
#include "CharFactory.h"

#include "Font.h"
#include "Color.h"

class TestFile
{
    public:
        TestFile();
        virtual ~TestFile();
        void testGraphics();

    private:
        WINDOW * win;
};

#endif // TESTFILE_H
