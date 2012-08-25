#ifndef ADDIMAGE_H
#define ADDIMAGE_H

#include "paintoperation.h"
#include <QImage>
#include <QPoint>

class AddImage : public PaintOperation
{
public:
    AddImage(QPoint const&, QImage const&);
    void operate(QPainter&);
private:
    QPoint point;
    QImage image;
};

#endif // ADDIMAGE_H
