#ifndef ADDLINE_H
#define ADDLINE_H

#include "paintoperation.h"
#include <QLine>
#include <QPainter>
#include <QImage>

class AddLine : public PaintOperation
{
public:
    AddLine(QLine const&);
    void operate(QPainter&);

private:
    QLine line;
};

#endif // ADDLINE_H
