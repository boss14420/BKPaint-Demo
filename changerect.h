#ifndef CHANGERECT_H
#define CHANGERECT_H

#include "paintoperation.h"
#include <QRect>

class QImage;

class ChangeRect : public PaintOperation
{
public:
    ChangeRect(QRect const&, QPoint const&, QPoint const&, QImage*);
    void operate(QPainter&);

private:
    QRect rect;
    QPoint lastTopLeft, topLeft;
    QImage *tempImage;
};

#endif // CHANGERECT_H
