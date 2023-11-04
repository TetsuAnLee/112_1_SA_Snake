#include "player.h"

#include <QGraphicsScene>
#include <QTimer>

Player::Player()
{
    setPixmap(QPixmap(":../Pacman.png"));
    this->timer = new QTimer(this);
    connect(this->timer, &QTimer::timeout, this, &Player::move);
    this->timer->start(50);
}
void Player::move(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    foreach (QGraphicsItem *item, colliding_items) {
        Food * food = dynamic_cast<Food*>(item);
        if (food) {
            emit eating(this, food);
            scene()->removeItem(food);

            return;
        }
    }

    setPos(x()+5, y()+5);
}
