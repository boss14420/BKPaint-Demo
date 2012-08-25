#include <QImage>
#include <QTimerEvent>

#include "player.h"
#include "canvas.h"
#include "paintoperation.h"

#include "addline.h"
#include "addrect.h"
#include "changeline.h"
#include "changerect.h"
#include "mousepress.h"

Player::Player(Canvas *canvas) :
    QObject(canvas), canvas(canvas),
    image(new QImage(canvas->size (), QImage::Format_ARGB32_Premultiplied)),
    tempImage(new QImage()),
    painter(image)
{
}

Player::~Player() {
    painter.end();
    delete image;
    delete tempImage;

    foreach(PaintOperation *po, operations)
        delete po;
}

QImage const* Player::getImage() const {
    return image;
}

void Player::play () {
    image->fill (Qt::white);
    currentOp = operations.begin ();
    canvas->setMode (Canvas::Replay);
//    painter.end();
    timerId = startTimer (50);
}

void Player::timerEvent (QTimerEvent *event) {
    if(event->timerId () == timerId) {
        if(currentOp != operations.end ()) {
            (*currentOp)->operate(painter);
            canvas->repaint();
            ++currentOp;
        } else
            killTimer (timerId);
    }
}

void Player::addLine (const QLine &line)  {
    operations << new AddLine (line);
}

void Player::addRect (const QRect &rect)  {
    operations << new AddRect (rect);
}

void Player::changeLine (const QLine &line,
                         const QPoint &lastTopLeft, const QPoint &topLeft)
{
    operations << new ChangeLine (line, lastTopLeft, topLeft, tempImage);
}

void Player::changeRect (const QRect &rect,
                         const QPoint &lastTopLeft, const QPoint &topLeft)
{
    operations << new ChangeRect (rect, lastTopLeft, topLeft, tempImage);
}

void Player::mousePress(const QPoint &point) {
    operations << new MousePress(point, tempImage);
}
