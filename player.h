#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QList>
#include <QLine>
#include <QRect>
#include <QPainter>
#include <memory>

class PaintOperation;
class QImage;
class Canvas;
class QEvent;

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(Canvas *canvas);
    virtual ~Player();

    QImage* getImage();

//    void addLine(QLine const&);
//    void addRect(QRect const&);
////    void addImage(QImage const&);
//    void changeLine(QLine const&, QPoint const&, QPoint const&);
//    void changeRect(QRect const&, QPoint const&, QPoint const&);
//    void mousePress(QPoint const&);

    template<class Event> void addEvent(Event*);

    bool isEnd();

public slots:
    void play();
    void stop();

protected:
    void timerEvent (QTimerEvent *);

private:
    Canvas *canvas;
    QImage *image, *tempImage;
//    QPainter painter;
//    QList<PaintOperation*> operations;
//    QList<PaintOperation*>::iterator currentOp;

    QList<std::shared_ptr<QEvent> > events;
    QList<std::shared_ptr<QEvent> >::iterator currentEvent;

    int timerId;
};

#endif // PLAYER_H
