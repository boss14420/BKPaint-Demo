#include "mousepress.h"
#include <QImage>

MousePress::MousePress(QPoint const& point, QImage *tempImage)
    : point(point), tempImage(tempImage)
{
}

void MousePress::operate(QPainter& painter) {
    *tempImage = static_cast<QImage*>(painter.device())
                    ->copy(QRect(point, point));
}
