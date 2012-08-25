#ifndef CHANGELINE_H
#define CHANGELINE_H

#include "addline.h"
#include "addimage.h"

class ChangeLine : public PaintOperation
{
public:
    ChangeLine(AddLine const&, AddImage const&);
    void operate(QPainter &);

private:
    AddLine addline;
    AddImage addimage;
};

#endif // CHANGELINE_H
