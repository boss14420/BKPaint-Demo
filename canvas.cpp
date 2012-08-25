#include "canvas.h"
#include "ui_canvas.h"
#include <QPainter>
#include <QImage>
#include <QPicture>
#include <QMouseEvent>

#include <cstdlib>
#include <cmath>

#include "addline.h"
#include "addrect.h"
#include "addimage.h"
#include "changeline.h"
#include "changerect.h"

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

    painter.begin (image);
    painter.setPen (Qt::black);

    mousePress = false;

    connect (&timer, SIGNAL(timeout()), this, SLOT(operateNext()));
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
}

void Canvas::replay () {
    mode = Replay;
    currentOp = operations.begin ();
    tempImage = QImage(image->size (), QImage::Format_ARGB32_Premultiplied);
    tempImage.fill(Qt::white);
    painter.end();
    painter.begin (&tempImage);
    repaint();

    timer.setInterval (50);
    timer.start ();
}

void Canvas::operateNext () {
    if(currentOp != operations.end()) {
        painter.end();
        painter.begin (&tempImage);
        (*currentOp)->operate(painter);
        ++currentOp;
        repaint();
    } else
        timer.stop ();
}

void Canvas::paintEvent (QPaintEvent *) {
    painter.end();
    painter.begin (this);
    if(mode != Replay) {
        painter.drawImage (0, 0, *image);
    } else {
//        QList<PaintOperation*>::iterator pi;
//        for(pi = operations.begin (); pi != currentOp; ++pi)
//            (*pi)->operate(painter);
        painter.drawImage (0, 0, tempImage);
    }

//    QWidget::paintEvent (event);
}

void Canvas::resizeEvent (QResizeEvent *event) {
//    int w = Q
    QWidget::resizeEvent (event);
}

void Canvas::mousePressEvent (QMouseEvent *event) {
    startPoint = lastPoint = event->pos ();
    mousePress = true;
    tempImage = image->copy (QRect(startPoint, lastPoint));
//    tempImage = image->copy ()  ;
}

void Canvas::mouseMoveEvent (QMouseEvent *event) {
    if(mousePress) {
        painter.end();
        painter.begin(image);
        if(mode == FreeDraw) {
            painter.drawLine (lastPoint, event->pos());
            operations << new AddLine(QLine(lastPoint, event->pos()));
        } else {
            // restore old region
//            image->fill(Qt::transparent);
//            painter.fillRect ( std::min(startPoint.x(), lastPoint.x()),
//                               std::min(startPoint.y(), lastPoint.y()),
//                               tempImage.width (), tempImage.height (),
//                               Qt::transparent );
            QPoint topLeft(std::min(startPoint.x(), lastPoint.x()),
                            std::min(startPoint.y(), lastPoint.y()));
            painter.drawImage( topLeft, tempImage );
            AddImage addimage(topLeft, tempImage);
//            painter.drawImage (0, 0, tempImage);

            // save region
            int xmin = std::min(startPoint.x(), event->pos().x());
            int ymin = std::min(startPoint.y(), event->pos().y());
            int w    = std::abs (startPoint.x() - event->pos().x()) + 4;
            int h    = std::abs (startPoint.y() - event->pos().y()) + 4;
            tempImage = image->copy (xmin, ymin, w, h);

            switch(mode) {
            case DrawLine:
                painter.drawLine (startPoint, event->pos());
                operations << new ChangeLine(
                            AddLine(QLine(startPoint, event->pos())) , addimage);
                break;
            case DrawRectangle:
                painter.drawRect (xmin, ymin, w-4, h-4);
                operations << new ChangeRect(
                            AddRect(QRect(xmin, ymin, w-4, h-4)), addimage);
                break;
            default:
                break;
            }
        }
        lastPoint = event->pos();
        repaint ();
    }
}

void Canvas::mouseReleaseEvent (QMouseEvent *) {
//    switch(mode) {
//        case DrawLine:
//        case DrawRectangle:
//            painter.end();
//            painter.begin(picture);
//            painter.
//            break;
//        default:
//            break;
//    }
    mousePress = false;
}
