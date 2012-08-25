#ifndef CHANGELINE_H
#define CHANGELINE_H

#include "paintoperation.h"
#include <QLine>

class QImage;

class ChangeLine : public PaintOperation
{
public:
    ChangeLine(QLine const&, QPoint const&, QPoint const&, QImage*);
    void operate(QPainter &);

private:
    QLine line;
    QPoint lastTopLeft, topLeft;
    QImage *tempImage;
};

#endif // CHANGELINE_H
