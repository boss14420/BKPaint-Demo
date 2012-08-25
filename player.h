#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QList>
#include <QLine>
#include <QRect>
#include <QPainter>

class PaintOperation;
class QImage;
class Canvas;

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(Canvas *canvas);
    virtual ~Player();

    QImage const *getImage() const;

    void addLine(QLine const&);
    void addRect(QRect const&);
//    void addImage(QImage const&);
    void changeLine(QLine const&, QPoint const&, QPoint const&);
    void changeRect(QRect const&, QPoint const&, QPoint const&);
    void mousePress(QPoint const&);

    bool isEnd();

public slots:
    void play();

protected:
    void timerEvent (QTimerEvent *);

private:
    Canvas *canvas;
    QImage *image, *tempImage;
    QPainter painter;
    QList<PaintOperation*> operations;
    QList<PaintOperation*>::iterator currentOp;

    int timerId;
};

#endif // PLAYER_H
