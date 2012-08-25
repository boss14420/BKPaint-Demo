#include "changerect.h"

ChangeRect::ChangeRect(QRect const& r, QPoint const& p1, QPoint const& p2, QImage *i)
    : rect(r), lastTopLeft(p1), topLeft(p2), tempImage(i)
{
}

void ChangeRect::operate (QPainter &painter) {
    painter.drawImage (lastTopLeft, *tempImage);
    *tempImage = static_cast<QImage*>(painter.device ())
            ->copy (topLeft.x(), topLeft.y(), rect.width ()+4, rect.height ()+4);
    painter.drawRect (rect);
}
