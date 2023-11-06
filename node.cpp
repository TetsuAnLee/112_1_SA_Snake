#include "node.h"
#include "body.h"
#include <QPointF>
Node::Node(Body * new_body)
{
    this->data = new_body;
}

QPointF Node::getPos(){
    return this->data->pos();
}
int Node::getRotation(){
    return this->data->getRotation();
}
