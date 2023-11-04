#ifndef PLAYER_H
#define PLAYER_H
#include "food.h"
#include "body.h"
#include <QGraphicsPixmapItem>
#include <QObject>

class Player :public QGraphicsPixmapItem,public QObject
{
    Q_OBJECT
public:
    explicit Player(QPixmap pixmap);
    explicit Player();
    ~Player();

    qreal rotation() const;
    void setRotation(qreal newRotation);
    void rotateTo(qreal end, const int duration, const QEasingCurve curve);
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
