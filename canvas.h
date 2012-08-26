#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QEvent>
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
    enum DrawMode { DrawLine, DrawRectangle, FreeDraw };

public:
    explicit Canvas(QWidget *parent = 0);
    ~Canvas();

    QImage const* getImage() const;

    void setMode(DrawMode);

    friend class Player;

public slots:
    void setReplay(bool);

protected:
    void paintEvent (QPaintEvent *);
    void resizeEvent (QResizeEvent *);

    void mousePressEvent (QMouseEvent *);
    void mouseMoveEvent (QMouseEvent *);
    void mouseReleaseEvent (QMouseEvent *);

private:
    void processMousePress(QMouseEvent *);
    void processMouseMove(QMouseEvent *);
    void processMouseRelease(QMouseEvent *);

    Ui::Canvas *ui;

    QImage *image, *usingImage, tempImage;
    QPicture *picture;
    DrawMode mode;

    QPoint startPoint, lastPoint;
    QPainter painter;
    bool mousePress;
    bool isReplay;

    Player *player;
};

class CanvasChangeModeEvent : public QEvent {
public:
    CanvasChangeModeEvent(Canvas::DrawMode m)
        : QEvent(EventType), m(m)
    {}

    static const Type EventType = User;

    Canvas::DrawMode mode() const { return m; }
private:
    Canvas::DrawMode m;
};
#endif // CANVAS_H
