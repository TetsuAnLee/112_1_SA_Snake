#ifndef BODY_H
#define BODY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPointF>

class Body:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Body();
    Body(QPointF,int);
    int getRotation();
    QPointF getPos();
private:
    int rotation = 0;
};

#endif // BODY_H
