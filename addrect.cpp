#include "addrect.h"

AddRect::AddRect(QRect const& rect) : rect(rect)
{
}

void AddRect::operate (QPainter &painter) {
    painter.drawRect (rect);
}
