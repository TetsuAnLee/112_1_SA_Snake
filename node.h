#ifndef NODE_H
#define NODE_H
#include <QPointF>
#include <QObject>
#include <QWidget>

class Node: public QObject
{
    Q_OBJECT
public:
    Node();
    QPointF* getpos();
private:
    int x;
    int y;
};

#endif // NODE_H
