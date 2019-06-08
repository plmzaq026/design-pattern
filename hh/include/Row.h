#ifndef ROW_H
#define ROW_H
#include "Glyph.h"
class Row:public Glyph
{
    private:
        vector<Glyph*> gList;
    public:
        Row(){}
        void add(Glyph* g)
        {
            gList.push_back(g);
        }
        void remove(Glyph* g)
        {
            std::vector<Glyph*>::iterator iter=std::find(gList.begin(),gList.end(),g);
            gList.erase(iter);
        }
        Glyph * getChild(int i)
        {
            return (Glyph*)gList[i];
        }
        void display(Graphics * g)
        {
           for(int i =0 ; gList.begin() + i != gList.end();i ++)
            {
              ((Glyph*)gList[i])->display(g);
            }
        }
};


#endif // ROW_H
