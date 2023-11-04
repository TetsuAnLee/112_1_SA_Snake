#include "body.h"
#include <QTimer>
Body::Body()
{
    length = 1;
}
void Body::setprevious(Body * temp){
    this->previous = temp;
}
void Body::setnext(Body * temp){
    this->next = temp;
}
void Body::moveForward()
{
    //rotate to previous node
    //setTransformOriginPoint(previous->pos());//我覺得可能的答案

    int STEP_SIZE = 30;
    //change into radians
    double theata = qDegreesToRadians(rotation());

    double dx = STEP_SIZE * qCos(theata);
    double dy = STEP_SIZE * qSin(theata);
    //let bodypart follow previous node
    setPos(previous->pos()-QPointF(dx,dy));
}
Body* Body::getnext(){
    return next;
}
void Body::add_node(Body *body)
{   Body *temp = body;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Body *t = new Body;
    temp->setnext(t);
    t->setprevious(temp);
    length+=1;
}
int Body::getlength(){
    return length;
}
