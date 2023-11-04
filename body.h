#ifndef BODY_H
#define BODY_H
#include "node.h"
#include <QGraphicsPixmapItem>
#include <QWidget>

class Body :public Node, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Body();
    void operator=(const Body);
    int getlength();
public slots:
    void moveForward();
    void add_node(Body&);
private:
    int length;
};

#endif // BODY_H
