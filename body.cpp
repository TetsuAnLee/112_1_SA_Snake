#include "body.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
Body::Body()
{
    QPixmap pixmap(":/images/Pacman.png");
    pixmap = pixmap.scaled(50, 50); // 设置图像大小为50x50
    setPixmap(pixmap);
}
Body::Body(QPointF pos,int _rotation){
    QPixmap pixmap(":/images/Pacman.png");
    pixmap = pixmap.scaled(50, 50); // 设置图像大小为50x50
    setPixmap(pixmap);
    setPos(pos);
    this->rotation=_rotation;
}
int Body::getRotation(){
    return this->rotation;
}
void Body::setangle(int _rotation){
    this->rotation = _rotation;
    setRotation(rotation);
}
QPointF Body::getPos(){
    return this->pos();
}

