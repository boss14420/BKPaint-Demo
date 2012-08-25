#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPoint>
#include <QPainter>
#include <QList>
#include <QTimer>

class QImage;
class QPicture;
class PaintOperation;

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:
    enum DrawMode { DrawLine, DrawRectangle, FreeDraw, Replay };

public:
    explicit Canvas(QWidget *parent = 0);
    ~Canvas();

    QImage const* getImage() const;

    void setMode(DrawMode);

public slots:
    void replay();

protected:
    void paintEvent (QPaintEvent *);
    void resizeEvent (QResizeEvent *);

    void mousePressEvent (QMouseEvent *);
    void mouseMoveEvent (QMouseEvent *);
    void mouseReleaseEvent (QMouseEvent *);

private slots:
    void operateNext();

private:
    Ui::Canvas *ui;

    QImage *image, tempImage;
    QPicture *picture;
    DrawMode mode;

    QPoint startPoint, lastPoint;
    QPainter painter;
    bool mousePress;

    QList<PaintOperation*> operations;
    QList<PaintOperation*>::iterator currentOp;
    QTimer timer;
};

#endif // CANVAS_H
