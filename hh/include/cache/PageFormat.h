#ifndef PAGEFORMAT_H
#define PAGEFORMAT_H

#include "Paper.h"
class PageFormat {
public:
    int MIN_MARGIN = 12;
    int MIN_BODY_WIDTH = 48;
    int MIN_BODY_HEIGHT = 50;
private:
    int width;
    int height;

    int leftMargin;
    int rightMargin;

    int topMargin;
    int bottomMargin;

    PageFormat * DEFAULT;
    PageFormat(Paper *paper)
        {
            reset(paper);
        }
    PageFormat()
    {
        Paper * A4 = new Paper("A4", 21.0f, 29.7f, 3.17f, 3.17f, 2.54f, 2.54f);
        DEFAULT = new PageFormat(A4);
        reset(A4);
    }

    void reset(Paper *paper)
    {
        this->width = paper->width;
        this->height = paper->height;
        this->leftMargin = paper->leftMargin;
        this->rightMargin = paper->rightMargin;
        this->topMargin = paper->topMargin;
        this->bottomMargin = paper->bottomMargin;
    }
    int scaleWidth() {
        return width - leftMargin - rightMargin;
    }
    int scaleHeight() {
        return height - topMargin - bottomMargin;
    }
    int getLeftMargin() {
        return this->leftMargin;
    }
    int getTopMargin() {
        return this->topMargin;
    }
    int getHeight() {
        return height;
    }
    void setHeight(int height) {
        this->height = height;
    }
    int getWidth() {
        return width;
    }
    void setWidth(int width) {
        this->width = width;
    }
};

#endif // PAGEFORMAT_H
