#include "changerect.h"

ChangeRect::ChangeRect(AddRect const &ar, AddImage const &ai)
    : addrect(ar), addimage(ai)
{
}

void ChangeRect::operate (QPainter &painter) {
    addimage.operate(painter);
    addrect.operate(painter);
}
