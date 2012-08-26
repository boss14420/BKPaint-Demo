#include <QImage>
#include <QTimerEvent>
#include <QMouseEvent>

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
    tempImage(new QImage())
//    painter(image)
{
}

Player::~Player() {
//    painter.end();
    delete image;
    delete tempImage;

//    foreach(PaintOperation *po, operations)
//        delete po;
}

QImage* Player::getImage() {
    return image;
}

void Player::play () {
    image->fill (Qt::white);
//    currentOp = operations.begin ();
    currentEvent = events.begin();
//    painter.end();
    timerId = startTimer (50);
}

void Player::stop() {
    killTimer (timerId);
}

void Player::timerEvent (QTimerEvent *event) {
    if(event->timerId () == timerId) {
//        if(currentOp != operations.end ()) {
//            (*currentOp)->operate(painter);
//            canvas->repaint();

        if(currentEvent != events.end()) {
            QEvent *evt = (*currentEvent).get();
            switch(evt->type()) {
            case QEvent::MouseButtonPress:
                canvas->processMousePress(static_cast<QMouseEvent*>(evt));
                break;
            case QEvent::MouseMove:
                canvas->processMouseMove(static_cast<QMouseEvent*>(evt));
                break;
            case QEvent::MouseButtonRelease:
                canvas->processMouseRelease(static_cast<QMouseEvent*>(evt));
                break;
            case CanvasChangeModeEvent::EventType:
                canvas->setMode (static_cast<CanvasChangeModeEvent*>(evt)->mode ());
                break;
            default:
                break;
            }

//            ++currentOp;
            ++currentEvent;
        } else
            killTimer (timerId);
    }
}

//void Player::addLine (const QLine &line)  {
//    operations << new AddLine (line);
//}

//void Player::addRect (const QRect &rect)  {
//    operations << new AddRect (rect);
//}

//void Player::changeLine (const QLine &line,
//                         const QPoint &lastTopLeft, const QPoint &topLeft)
//{
//    operations << new ChangeLine (line, lastTopLeft, topLeft, tempImage);
//}

//void Player::changeRect (const QRect &rect,
//                         const QPoint &lastTopLeft, const QPoint &topLeft)
//{
//    operations << new ChangeRect (rect, lastTopLeft, topLeft, tempImage);
//}

//void Player::mousePress(const QPoint &point) {
//    operations << new MousePress(point, tempImage);
//}

template <class Event>
void Player::addEvent (Event *event) {
    switch(event->type()) {
        case QEvent::MouseButtonPress:
        case QEvent::MouseButtonRelease:
        case QEvent::MouseMove:
        case CanvasChangeModeEvent::EventType:
            events << std::shared_ptr<QEvent>(new Event(*event));
            break;
        default:
            break;
    }
}

template void
    Player::addEvent<QMouseEvent>(QMouseEvent*);
template void
    Player::addEvent<CanvasChangeModeEvent>(CanvasChangeModeEvent*);
