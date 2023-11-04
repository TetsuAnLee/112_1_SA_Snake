#include "node.h"

Node::Node()
{
}
QPointF* Node::getpos(){
    return new QPointF(x,y);
}
