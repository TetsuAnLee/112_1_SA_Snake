#ifndef FOOD_H
#define FOOD_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Food :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Food();
    ~Food();
};

#endif // FOOD_H
