#ifndef PARAGRAPHFORMAT_H
#define PARAGRAPHFORMAT_H


class ParagraphFormat
{
private:
    int INDENT_STEP = 28;
    int MIN_SCALEWIDTH = 32;

    int alignment = ALIGN_LEFT; // alignment.
    int width; // total width, equals PageFormat.scaleWidth
    int firstIndent = 24;   // first row indent.
    int leftIndent = 10;    // left indent.
    int rightIndent = 10;   // right indent.
    int rowSpace = 6;    // row space.

public:
    const int ALIGN_LEFT = 0;
    const int ALIGN_CENTER = 1;
    const int ALIGN_RIGHT = 2;

    int scaleWidth(bool firstRow) {
        if( firstRow ) { // first row should have additional indent.
            return ( width - leftIndent - rightIndent - firstIndent );
        }
        return ( width - leftIndent - rightIndent );
    }

    void increaseLeftIndent() {
        if( scaleWidth(false)-INDENT_STEP >= MIN_SCALEWIDTH )
            leftIndent += INDENT_STEP;
    }
    void increaseRightIndent() {
        if( scaleWidth(false)-INDENT_STEP >= MIN_SCALEWIDTH )
            rightIndent += INDENT_STEP;
    }
    int getAlignment() {
        return alignment;
    }
    void setAlignment(int alignment) {
        this->alignment = alignment;
    }
    int getFirstIndent() {
        return firstIndent;
    }
    void setFirstIndent(int firstIndent) {
        this->firstIndent = firstIndent;
    }
    int getLeftIndent() {
        return leftIndent;
    }
    void setLeftIndent(int leftIndent) {
        this->leftIndent = leftIndent;
    }
    int getRightIndent() {
        return rightIndent;
    }
    void setRightIndent(int rightIndent) {
        this->rightIndent = rightIndent;
    }
    int getRowSpace() {
        return rowSpace;
    }

    void setRowSpace(int rowSpace) {
        this->rowSpace = rowSpace;
    }
    int getWidth() {
        return this->width;
    }
    void setWidth(int width) {
        this->width = width;
    }
};

#endif // PARAGRAPHFORMAT_H
