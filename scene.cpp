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
void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        qDebug() << "Left mouse button clicked at (" << event->scenePos().x() << ", " << event->scenePos().y() << ")";
    }
    else if (event->button() == Qt::RightButton)
    {
        qDebug() << "Right mouse button clicked at (" << event->scenePos().x() << ", " << event->scenePos().y() << ")";
    }
    // 调用基类的处理函数，以确保其他鼠标事件仍然得到处理
    QGraphicsScene::mousePressEvent(event);
}
