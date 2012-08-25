#include "addline.h"
#include <QPainter>
#include <QLine>

AddLine::AddLine(QLine const &line) : line(line)
{
}

void AddLine::operate(QPainter &painter) {
    painter.drawLine (line);
}
