#ifndef STRINGFORMAT_H
#define STRINGFORMAT_H

#include "FontFactory.h"
#include "ColorFactory.h"

class StringFormat
{
    public:
        StringFormat(WINDOW * win,int cIndex = 0,int fIndex = 0, int sIndex = 0,int eIndex = 0)
        {
            this->win = win;
            ColorFactory * cf = new ColorFactory;
            cf->createColor(win,cIndex);
            FontFactory * ff = new FontFactory;
            ff->createFont(win,fIndex);
            startIndex = sIndex;
            endIndex = eIndex;
        }

        virtual ~StringFormat()
        {
            if(_color)
            {
                delete _color;
            }
            if(_font)
            {
                delete _font;
            }
        }
        Font * getFont()
        {
            return _font;
        }
        Color* getColor()
        {
            return _color;
        }
        void setFont(int index = 0)
        {
            FontFactory * ff = new FontFactory;
            ff->createFont(win,index);
        }
        void setColor(int index = 0)
        {
            ColorFactory * ff = new ColorFactory;
            ff->createColor(win,index);
        }
        void increase(int n)
        {
            endIndex += n;
        }
        void move(int steps)
        {
            this->startIndex += steps;
            this->endIndex += steps;
        }
        bool contains(int index)
        {
            return ( (this->startIndex<=index) && (index<=this->endIndex) );
        }
        int getStartIndex()
        {
            return startIndex;
        }
        int getEndIndex()
        {
            return endIndex;
        }
        void setStartIndex(int index)
        {
            startIndex = index;
        }
        void setEndIndex(int index)
        {
            endIndex = index;
        }
    private:
        WINDOW * win;
        Color* _color;
        Font * _font;
        int startIndex;
        int endIndex;
};

#endif // STRINGFORMAT_H
