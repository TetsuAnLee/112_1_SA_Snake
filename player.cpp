#include "player.h"

#include <QGraphicsScene>
#include <QTimer>

Player::Player()
{
    setPixmap(QPixmap(":../Pacman.png"));
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player::move);
    timer->start(50);
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
void Player::add_body(Body * newBody){
    Body *now = newBody;
    if(now==nullptr){
        head = newBody;
    }
    else{
        while(now->getnext()!=nullptr){
            now = now->getnext();
        }
        now->setnext(newBody);

    }
}
QPointF* Player::getpos(){
    return new QPointF(pos());
}
