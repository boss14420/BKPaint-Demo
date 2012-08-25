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
class Player;

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

private:
    Ui::Canvas *ui;

    QImage *image, tempImage;
    QPicture *picture;
    DrawMode mode;

    QPoint startPoint, lastPoint;
    QPainter painter;
    bool mousePress;

    Player *player;
};

#endif // CANVAS_H
