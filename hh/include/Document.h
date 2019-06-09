#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "Paragraph.h"
#include "Page.h"
class Document
{
    public:
        Document();
        virtual ~Document();
    private:
        Paragraph * p;
};

#endif // DOCUMENT_H
