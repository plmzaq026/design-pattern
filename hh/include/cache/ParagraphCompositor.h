#ifndef PARAGRAPHCOMPOSITOR_H
#define PARAGRAPHCOMPOSITOR_H

#include "Paragraph.h"
class ParagraphCompositor
{
private:
    vector<char> BREAK_CHAR;
    Paragraph * paragraph;
    bool isBreakGlyph(Glyph* g)
    {
        if(typeid(*g).name() ==  typeid(Char).name())
        {
            char c = ((Char*)g)->getValue();
            for(int i=0; i<BREAK_CHAR.size(); i++)
            {
                if(BREAK_CHAR[i]==c)
                    return true;
            }
            return false;
        }
        return true;
    }
public:
    ParagraphCompositor()
    {
        char ch[] = {' ', ',', '.', ';', ':', '\r', '\t', '?', '!'};
        for(int i =0 ;i < 9;i ++)
            BREAK_CHAR.push_back(ch[i]);
        paragraph = NULL;
    }
    virtual ~ParagraphCompositor(){};

};

#endif // PARAGRAPHCOMPOSITOR_H
