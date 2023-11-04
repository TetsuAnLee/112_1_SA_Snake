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
    void moveForward();
    void setprevious(Body *);
    void setnext(Body *);
    Body *previous;
    Body *next;
public slots:
    void add_node(Body*);
private:
    int length;
};

#endif // BODY_H
