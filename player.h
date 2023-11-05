#ifndef PLAYER_H
#define PLAYER_H
#include "food.h"
#include "body.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QWidget>

class Player :public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Player(QPixmap pixmap);
    explicit Player();
    ~Player();
    void add_body(Body*);
    QPointF* getpos();
public slots:
    void move();
signals:
    void eating(Food *food);
private:
    Body *head;
    qreal m_rotation;
    QTimer *timer;
};

#endif // PLAYER_H
