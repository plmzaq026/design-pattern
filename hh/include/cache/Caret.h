#ifndef CARET_H
#define CARET_H


class Caret
{
private:
    int pageIndex = 0;
    int rowIndex = 0;
    int columnIndex = 0;
public:
    Caret(int pageIndex, int rowIndex, int columnIndex)
    {
        this->pageIndex = pageIndex;
        this->rowIndex = rowIndex;
        this->columnIndex = columnIndex;
    }
};

#endif // CARET_H
