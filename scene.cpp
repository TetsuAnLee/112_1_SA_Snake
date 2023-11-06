#include "scene.h"
#include "body.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

Scene::Scene(QObject *parent): QGraphicsScene(parent)
{
    body = new Body();
    //test->setRect(0,0,100,100);
    body->setPos(200,300);
    addItem(body);
}
Scene::~Scene(){

}

