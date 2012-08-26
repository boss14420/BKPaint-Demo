#include "canvas.h"
#include "ui_canvas.h"
#include <QPainter>
#include <QImage>
#include <QPicture>
#include <QMouseEvent>

#include <cstdlib>
#include <cmath>

#include "player.h"
extern template
    void Player::addEvent<QMouseEvent>(QMouseEvent*);
extern template
    void Player::addEvent<CanvasChangeModeEvent>(CanvasChangeModeEvent*);


Canvas::Canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canvas)
{
    ui->setupUi(this);

    // set background
//    QPalette p(palette ());
//    p.setColor (QPalette::Background, Qt::transparent);
//    setPalette (p);

    setBackgroundRole (QPalette::Base);
//    setAttribute (Qt::WA_TranslucentBackground, true);

    image = new QImage(size (), QImage::Format_ARGB32_Premultiplied);
//    image->fill (Qt::transparent);
    image->fill (Qt::white);
    usingImage = image;

    painter.begin (image);
    painter.setPen (Qt::black);

    mousePress = false;
    isReplay = false;

    player = new Player(this);
}

Canvas::~Canvas()
{
    painter.end();

    delete ui;
    delete image;
}

QImage const * Canvas::getImage () const {
    return image;
}

void Canvas::setMode (DrawMode m) {
    mode = m;

    if(!isReplay) {
        CanvasChangeModeEvent evt(m);
        player->addEvent(&evt);
    }
}

void Canvas::setReplay (bool replay) {
    if(replay) {
        usingImage = player->getImage ();
        isReplay = true;
        player->play ();
    } else {
        isReplay = false;
        player->stop();
        usingImage = image;
        repaint ();
    }
}

void Canvas::paintEvent (QPaintEvent *) {
    painter.end();
    painter.begin (this);
//    if(mode == Replay) {
//        painter.drawImage (0, 0, *player->getImage());
//    } else {
//        painter.drawImage (0, 0, *image);
//    }
    painter.drawImage (0, 0, *usingImage);

//    QWidget::paintEvent (event);
}

void Canvas::resizeEvent (QResizeEvent *event) {
//    int w = Q
    QWidget::resizeEvent (event);
}

void Canvas::mousePressEvent (QMouseEvent *event) {
    if(!isReplay) {
        processMousePress (event);
        player->addEvent (event);
    }
}

void Canvas::mouseMoveEvent (QMouseEvent *event) {
    if(!isReplay) {
        processMouseMove (event);
        player->addEvent (event);
    }
}

void Canvas::mouseReleaseEvent (QMouseEvent *event) {
    if(!isReplay) {
        processMouseRelease (event);
        player->addEvent (event);
    }
}

void Canvas::processMousePress (QMouseEvent *event) {
//    if(mode != Replay) {
        startPoint = lastPoint = event->pos ();
        mousePress = true;
        tempImage = usingImage->copy (QRect(startPoint, startPoint));
//        player->mousePress(startPoint);
//    }
}

void Canvas::processMouseMove (QMouseEvent *event) {
    if(mousePress) {
        painter.end();
        painter.begin(usingImage);
        if(mode == FreeDraw) {
            painter.drawLine (lastPoint, event->pos());
//            player->addLine (QLine(lastPoint, event->pos ()));
        } else {
            // restore old region
//            image->fill(Qt::transparent);
            QPoint lastTopLeft(std::min(startPoint.x(), lastPoint.x()),
                            std::min(startPoint.y(), lastPoint.y()));
            painter.drawImage(lastTopLeft, tempImage );

            // save region
            int xmin = std::min(startPoint.x(), event->pos().x());
            int ymin = std::min(startPoint.y(), event->pos().y());
            int w    = std::abs (startPoint.x() - event->pos().x()) + 4;
            int h    = std::abs (startPoint.y() - event->pos().y()) + 4;
            tempImage = usingImage->copy (xmin, ymin, w, h);

            switch(mode) {
            case DrawLine:
                painter.drawLine (startPoint, event->pos());
//                player->changeLine (QLine(startPoint, event->pos()), lastTopLeft, QPoint(xmin, ymin));
                break;
            case DrawRectangle:
                painter.drawRect (xmin, ymin, w-4, h-4);
//                player->changeRect (QRect(xmin, ymin, w-4, h-4), lastTopLeft, QPoint(xmin, ymin));
                break;
            default:
                break;
            }
        }
        lastPoint = event->pos();
        repaint ();
    }
}

void Canvas::processMouseRelease (QMouseEvent *) {
    mousePress = false;
}
