#ifndef MOUSEPRESS_H
#define MOUSEPRESS_H

#include "paintoperation.h"

class QImage;

class MousePress : public PaintOperation
{
public:
    MousePress(QPoint const&, QImage*);
    void operate(QPainter&);

private:
    QPoint point;
    QImage *tempImage;
};

#endif // MOUSEPRESS_H
