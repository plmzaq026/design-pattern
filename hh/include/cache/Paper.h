#ifndef PAPER_H
#define PAPER_H

#include "Calc.h"
class Paper
{
public:
    string name;

    int width;
    int height;

    int leftMargin;
    int rightMargin;

    int topMargin;
    int bottomMargin;

    // To make sure that client cannot create a new instance:
    Paper()
    {
        setVal("A4", 21.0f, 29.7f, 3.17f, 3.17f, 2.54f, 2.54f);
    }
    void setVal(string name, float width, float height,
        float leftMargin, float rightMargin, float topMargin,
        float bottomMargin)
    {
        Calc * calc;
        this->name = name;
        this->width = calc->cm2pixel(width);
        this->height = calc->cm2pixel(height);
        this->leftMargin = calc->cm2pixel(leftMargin);
        this->rightMargin = calc->cm2pixel(rightMargin);
        this->topMargin = calc->cm2pixel(topMargin);
        this->bottomMargin = calc->cm2pixel(bottomMargin);
    }
    Paper(string name, float width, float height,
        float leftMargin, float rightMargin, float topMargin,
        float bottomMargin)
    {
        Calc * calc;
        this->name = name;
        this->width = calc->cm2pixel(width);
        this->height = calc->cm2pixel(height);
        this->leftMargin = calc->cm2pixel(leftMargin);
        this->rightMargin = calc->cm2pixel(rightMargin);
        this->topMargin = calc->cm2pixel(topMargin);
        this->bottomMargin = calc->cm2pixel(bottomMargin);
    }
    Paper * A4()
    {
        return new Paper("A4", 21.0f, 29.7f, 3.17f, 3.17f, 2.54f, 2.54f);
    }
    Paper * CUSTOM()
    {
        return new Paper("Custom", 18.0f, 24.0f, 1.2f, 1.2f, 1.0f, 1.0f);
    }
};
#endif // PAPER_H
