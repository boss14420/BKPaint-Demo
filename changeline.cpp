#include "changeline.h"
#include <cstdlib>
#include <cmath>

ChangeLine::ChangeLine(QLine const& l, QPoint const& p1, QPoint const& p2, QImage* i)
    : line(l), lastTopLeft(p1), topLeft(p2), tempImage(i)
{
}

void ChangeLine::operate (QPainter &painter) {
    painter.drawImage (lastTopLeft, *tempImage);
    *tempImage = static_cast<QImage*>(painter.device ())
                ->copy (topLeft.x(), topLeft.y(),
                        std::abs(line.dx ())+4, std::abs(line.dy ())+4);
    painter.drawLine (line);
}
