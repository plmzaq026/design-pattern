#ifndef FONT_H
#define FONT_H

#include <bits/stdc++.h>
using namespace std;
class Font
{
private:
    string name;
    int size;
    bool bold;
    bool italic;
    bool underlined;
    int _height; // font's height.
    int refCount = 0; // reference count.
    string m_tostring = ""; // cache "tostring()"
    // store the defaultGraphics:
    //Graphics * g = null;
public:
    int getRefCount()
    {
        return refCount;
    }
    Font(string name = "", int size = 0, bool bold = false, bool italic = false, bool underlined = false)
    {
        this->name = name;
        this->size = size;
        this->bold = bold;
        this->italic = italic;
        this->underlined = underlined;

    }
    bool equals(Font & f)
    {
        return this->name == f.name &&
            this->size == f.size &&
            this->bold == bold &&
            this->italic == italic&&
            this->underlined == underlined;
    }
    string getName() {
        return name;
    }
    int getSize() {
        return size;
    }
    bool getBold() {
        return bold;
    }
    bool getItalic() {
        return italic;
    }
    bool getUnderlined() {
        return underlined;
    }
    int height() {
        return this->_height;
    }
    int hashCode() {
        string tmp = this->tostring();
        unsigned int seed = 31;
        unsigned int hash = 0;
        for(int i = 0;i < tmp.length();i ++)
        {
            hash = hash * seed + tmp[i];
        }
        return (hash & 0x7FFFFFFF);
    }
    string tostring()
    {
        if(m_tostring=="")
        {
            m_tostring = toKey(name, size, bold, italic, underlined);
        }
        return m_tostring;
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
    static string toKey(string name, int size, bool bold, bool italic, bool underlined)
    {
        string tmp = to_String(size);
        return name + "_" + tmp + "_" +
            (bold ? "B" : "b") +
            (italic ? "I" : "i") +
            (underlined ? "U" : "u");
    }
     void removeRef() {
        this->refCount --;
    }
    void addRef()
    {
        this->refCount ++;
    }
    void dispose()
    {
        this->removeRef();
        if(this->refCount>0)
            return;
        // if no other object which referenced this font,
        // then distroy it:
        dispose();
    }
};

#endif // FONT_H
