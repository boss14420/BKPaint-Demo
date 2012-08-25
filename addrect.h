#ifndef ADDRECT_H
#define ADDRECT_H

#include "paintoperation.h"
#include <QRect>

class AddRect : public PaintOperation
{
public:
    AddRect(QRect const&);
    void operate(QPainter&);

private:
    QRect rect;
};

#endif // ADDRECT_H
