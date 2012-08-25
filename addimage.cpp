#include "addimage.h"

AddImage::AddImage(QPoint const& point, QImage const& image)
    : point(point), image(image)
{
}

void AddImage::operate (QPainter &painter) {
    painter.drawImage (point, image);
}
