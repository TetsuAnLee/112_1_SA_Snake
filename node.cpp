#include "node.h"
#include "body.h"
#include <QPointF>
Node::Node(Body * new_body)
{
    this->data = new_body;
    prev = nullptr;
    next = nullptr;
}
Node* Node::getNext() const
{
    return this->next;
}
Node* Node::getPrevious() const
{
    return this->prev;
}
void Node::setPrevious(Body* _previousBody)
{
    this->prev = new Node(_previousBody);
}
void Node::setPrevious(Node* _previousNode)
{
    this->prev = _previousNode;
}
void Node::setNext(Body* _nextBody)
{
    this->next = new Node(_nextBody);
    this->next->setPrevious(this);
}
