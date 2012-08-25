#ifndef PAINTOPERATION_H
#define PAINTOPERATION_H

#include <QPainter>

class PaintOperation
{
public:
    PaintOperation();
    virtual void operate(QPainter&) = 0;
};

#endif // PAINTOPERATION_H
