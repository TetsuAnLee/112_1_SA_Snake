#ifndef BODY_H
#define BODY_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Body:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Body();
};

#endif // BODY_H
