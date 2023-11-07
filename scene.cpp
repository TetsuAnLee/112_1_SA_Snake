#include "scene.h"
#include "body.h"
#include "food.h"
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
    food = new Food();
    food->setPos(20,20);
    addItem(food);
    AddLength();
    AddLength();
    AddLength();
    AddLength();
    AddLength();
    AddLength();
    QObject::connect(&timer, &QTimer::timeout, this, &Scene::forward);
    timer.start(100); // 每隔1秒触发一次定时器事件
    //AddLength();
}
Scene::~Scene(){

}
void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QPointF snakeHeadPos = head[0]->pos();
        QPointF mousePos = event->scenePos();
        qreal angle = qRadiansToDegrees(qAtan2(mousePos.y() - snakeHeadPos.y(), mousePos.x() - snakeHeadPos.x()));
        head[0]->setangle(angle);
        //qDebug() << "Left mouse button clicked at (" << event->scenePos().x() << ", " << event->scenePos().y() << ")";
    }
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
        QPointF newPosition = currentPosition - QPointF(80 * qCos(qDegreesToRadians(currentRotation)), 80 * qSin(qDegreesToRadians(currentRotation)));
        next_body = new Body(newPosition, currentRotation);
        head.append(next_body);
    }
    addItem(next_body);
}

void Scene::keyPressEvent(QKeyEvent *event) {
    qreal currentRotation = head[0]->getRotation();
    qreal rotationStep = 30;
    if (event->key() == Qt::Key_Left) {
        currentRotation -= rotationStep;
    } else if (event->key() == Qt::Key_Right) {
        currentRotation += rotationStep;
    }
    head[0]->setangle(currentRotation);
}


void Scene::forward() {
    qDebug() << "1s forward";

    qreal prev_angle = head[0]->getRotation();
    QPointF prev_pos = head[0]->pos();
    qreal step = 30;
    QPointF newPosition = prev_pos + QPointF(qCos(qDegreesToRadians(prev_angle)) * step, qSin(qDegreesToRadians(prev_angle)) * step);
    for (int i = head.size() - 1; i > 0; i--) {
        head[i]->setPos(head[i - 1]->getPos());  // 设置新位置
        head[i]->setangle(head[i - 1]->getRotation());  // 设置新角度
    }
    head[0]->setPos(newPosition);
    head[0]->setangle(prev_angle);
    for (int i = 0; i<head.size(); i++)
        qDebug() << "Head " << i << " Position: " << head[i]->getRotation();  // 打印更新后的位置
    collidesWithItem();
}
void Scene::collidesWithItem() {
    if (head[0]->collidesWithItem(food)) {
        removeItem(food);
        food = new Food();
        addItem(food);
        AddLength();
    }
}

