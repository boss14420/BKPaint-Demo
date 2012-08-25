#ifndef CHANGERECT_H
#define CHANGERECT_H

#include "addrect.h"
#include "addimage.h"

class ChangeRect : public PaintOperation
{
public:
    ChangeRect(AddRect const&, AddImage const&);
    void operate(QPainter&);

private:
    AddRect addrect;
    AddImage addimage;
};

#endif // CHANGERECT_H
