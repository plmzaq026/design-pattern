#ifndef STRINGFORMAT_H
#define STRINGFORMAT_H
/**克隆模式**/
#include "Font.h"
#include "Color.h"
class StringFormat
{
private:
    int startIndex;
    int endIndex;
    Font * font;
    Color * color;
public:
    StringFormat(Font* font = NULL, Color* color = NULL, int startIndex = 0, int endIndex = 0)
    {
        if(color && font && 0<=startIndex /*&& endIndex<paragraph.getGlyphsCount()*/ && startIndex<=endIndex )
        {
            this->font = font;
            this->color = color;
            this->startIndex = startIndex;
            this->endIndex = endIndex;
        }
        else
        {
            this->font = new Font("Arial",12,true,true,true);
            this->color = new Color;
            this->startIndex = this->endIndex = 0;
        }
    }
    Font* getFont()
    {
        return this->font;
    }
    void setFont(Font* font)
    {
        this->font = font;
    }
    /**
     * If some Char(s) are inserted in the range represented by
     * this StringFormat, then use increase() method to update it.
     *
     * @param n : How many Char(s) are inserted.
     */
    void increase(int n) {
        this->endIndex += n;
    }
    void move(int steps)
    {
        this->startIndex += steps;
        this->endIndex += steps;
    }
    bool equals(StringFormat sf)
    {
        return false;
    }
    bool contains(int index)
    {
        return ( (this->startIndex<=index) && (index<=this->endIndex) );
    }

    Color* getColor()
    {
        return this->color;
    }
    int getStartIndex()
    {
        return this->startIndex;
    }
    int getEndIndex()
    {
        return this->endIndex;
    }

    void setStartIndex(int startIndex)
    {
        this->startIndex = startIndex;
    }

    static string to_String(int n)
    {
        int m = n;
        char s[233];
        char ss[233];
        int i=0,j=0;
        if (n < 0)// 处理负数
        {
            m = 0 - m;
            j = 1;
            ss[0] = '-';
        }
        while (m>0)
        {
            s[i++] = m % 10 + '0';
            m /= 10;
        }
        s[i] = '\0';
        i = i - 1;
        while (i >= 0)
        {
            ss[j++] = s[i--];
        }
        ss[j] = '\0';
        return ss;
    }

    void setEndIndex(int endIndex)
    {
        this->endIndex = endIndex;
    }
    string toString()
    {
        return "[" + to_String(this->startIndex) + ", " + to_String(this->endIndex) + "]";
    }
};

#endif // STRINGFORMAT_H
