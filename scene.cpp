#include "scene.h"
#include "food.h"
#include "body.h"

#include <QDebug>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

Scene::Scene(QObject *parent): QGraphicsScene(parent)
{
    player = new Player();
    connect(player,&Player::eating,this,&Scene::increaselong);
    player->setpos(50,50);
    addItem(player);
    tail= new Body();
    player->setnext(tail);
    tail->setprevious(player);
    tail->setPos(player->pos());
    addItem(tail);
    while(tail->getlength()<5){
        tail->add_node(tail);
    }

}

void Scene::keyPressEvent(QKeyEvent *event)
{
    int STEP_SIZE = 30;

    double theata = qDegreesToRadians(30);

    double dx = STEP_SIZE * qCos(theata);
    double dy = STEP_SIZE * qSin(theata);
    QPointF pos = player->pos();
    if (event->key() == Qt::Key_Left) {
        player->setPos(pos + QPointF(dx, -dy));
    } else if (event->key() == Qt::Key_Right) {
        player->setPos(pos + QPointF(dx, dy));
    }

}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {   QPointF mousePos = event->scenePos();
        QLineF line(event->scenePos(),mousePos);
        line.setLength(1.0);

        QTimer* timer =new QTimer(this);
        connect(timer, &QTimer::timeout, this,[this,line](){
            player->setPos(line.dx(),line.dy());
        });
        timer->start(10);

        connect(timer, &QTimer::timeout, timer, &QTimer::deleteLater);
    }
}

void Scene::spawnFood()
{
    // Create a Food
    Food *food = new Food();
    addItem(food);
}
void Scene::increaselong(Food *food){
    removeItem(food);
    delete(food);
    tail->add_node(tail);
    spawnFood();
}
;
