#ifndef NODE_H
#define NODE_H
#include <QObject>
#include <QWidget>

class Node: public QObject
{
    Q_OBJECT
public:
    Node();
    void setprevious(Node *);
    void setnext(Node *);
private:
    Node * previous;
    Node * next;
    QTimer* timer;
};

#endif // NODE_H
