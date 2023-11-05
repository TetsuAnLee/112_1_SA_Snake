#ifndef BODY_H
#define BODY_H
#include "node.h"
#include <QWidget>

class Body :public Node
{
public:
    Body();
    void operator=(const Body);
    int getlength();
    void moveForward();
    void setprevious(Body *);
    void setnext(Body *);
    Body* getnext();
public slots:
    void add_node(Body*);
private:
    Body *previous;
    Body *next;
    int length;
};

#endif // BODY_H
