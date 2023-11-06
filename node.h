#ifndef NODE_H
#define NODE_H
#include "body.h"

class Node
{
public:
    Node(Body *);
    Node* getNext() const;
    void setNext(Body*);
    Node* getPrevious() const; // Add getPrevious function
    void setPrevious(Body*); // Add setPrevious function
    void setPrevious(Node*); // Add setPrevious function
private:
    Body * data;
    Node * prev;
    Node * next;
};

#endif // NODE_H
