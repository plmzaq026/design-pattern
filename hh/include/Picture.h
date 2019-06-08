#ifndef PICTURE_H
#define PICTURE_H


class Picture:public Glyph
{
private:
    string pic;
public:
    Picture(const string str = "picture.jpg")
    {
        pic = str;
    };
    virtual ~Picture(){};
    Picture* getChild(int i)
    {
        return NULL;
    }
    string getValue()
    {
        return pic;
    }
    bool equals(Picture & p)
    {
        return p.pic == this->pic;
    }
    void display(Graphics* g)
    {
        g->draw_string(pic);
    }
};


#endif // PICTURE_H
