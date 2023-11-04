#include "node.h"

Node::Node()
{

}
void Node::setprevious(Node * temp){
    this->previous = temp;
}
void Node::setnext(Node * temp){
    this->next = temp;
}
