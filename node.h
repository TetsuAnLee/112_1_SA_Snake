#ifndef NODE_H
#define NODE_H
#include "body.h"
#include <QPointF>
class Node
{
public:
    Node(Body *);
    QPointF getPos();
    int getRotation();
private:
    Body * data;
};

#endif // NODE_H
