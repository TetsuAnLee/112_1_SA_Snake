#ifndef PLAYER_H
#define PLAYER_H
#include "food.h"
#include "node.h"
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class Player : public Node ,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Player(QPixmap pixmap);
    explicit Player();
    ~Player();

    qreal rotation() const;
    void setRotation(qreal newRotation);
    void rotateTo(qreal end, const int duration, const QEasingCurve curve);
    void setpos(int,int);
    qreal y() const;
    void setY(qreal newY);
    qreal x() const;
    void setX(qreal newX);

public slots:
    void move();

signals:
    void eating(Player *player, Food *food);
private:
    qreal m_rotation;
    qreal m_y;
    qreal m_x;
    QPropertyAnimation *rotationAnimation;
    QPropertyAnimation *yAnimation;
    QPropertyAnimation *xAnimation;
};

#endif // PLAYER_H
