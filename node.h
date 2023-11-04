#ifndef NODE_H
#define NODE_H
#include <QObject>
#include <QWidget>

class Node: public QObject
{
    Q_OBJECT
public:
    Node();
    QTimer *timer;
};

#endif // NODE_H
