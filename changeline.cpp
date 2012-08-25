#include "changeline.h"

ChangeLine::ChangeLine(AddLine const& al, AddImage const& ai)
    : addline(al), addimage(ai)
{
}

void ChangeLine::operate (QPainter &painter) {
    addimage.operate (painter);
    addline.operate (painter);
}
