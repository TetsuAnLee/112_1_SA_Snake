#include "scene.h"
#include "body.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

Scene::Scene(QObject *parent): QGraphicsScene(parent)
{
    /*
    body = new Body();
    //test->setRect(0,0,100,100);
    body->setPos(200,300);
    addItem(body);
    */
    AddLength();
    AddLength();
    AddLength();
    AddLength();
    AddLength();
    AddLength();
    QObject::connect(&timer, &QTimer::timeout, this, &Scene::forward);
    timer.start(1000); // 每隔1秒触发一次定时器事件
    //AddLength();
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
void Scene::AddLength(){
    //head->append()
    Body * next_body;
    if(head.size()==0){
        next_body = new Body(QPointF(200,300),30);
        head.append(next_body);
    }else{
        QPointF currentPosition = head.at(head.size()-1)->getPos(); // 获取当前节点的位置
        qreal currentRotation = head.at(head.size()-1)->getRotation(); // 获取当前节点的角度
        // 计算新节点的位置，加上角度偏移和 50 像素的距离
        QPointF newPosition = currentPosition - QPointF(50 * qCos(qDegreesToRadians(currentRotation)), 50 * qSin(qDegreesToRadians(currentRotation)));
        next_body = new Body(newPosition, currentRotation);
        head.append(next_body);
    }
    addItem(next_body);
}
void Scene::forward() {
    qDebug() << "1s forward";

    qreal prev_angle = head[0]->getRotation();
    QPointF prev_pos = head[0]->pos();
    qreal step = 50;
    QPointF newPosition = prev_pos + QPointF(qCos(qDegreesToRadians(prev_angle)) * step, qSin(qDegreesToRadians(prev_angle)) * step);
    for (int i = head.size() - 1; i > 0; i--) {
        head[i]->setPos(head[i - 1]->getPos());  // 设置新位置
        head[i]->setRotation(head[i - 1]->getRotation());  // 设置新角度
    }
    head[0]->setPos(newPosition);
    head[0]->setRotation(prev_angle);
    for (int i = 0; i<head.size(); i++)
        qDebug() << "Head " << i << " Position: " << head[i]->getRotation();  // 打印更新后的位置
}

