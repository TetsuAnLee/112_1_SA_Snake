#ifndef SCENE_H
#define SCENE_H
#include "body.h"
#include "node.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    ~Scene();
    void startGame();
    void setpos(int,int);
    bool getGameOn() const;
    void setGameOn(bool newGameOn);
    void AddLength();
private:
    bool gameOn;
    QList<Body*> head;
    Body *body;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SCENE_H
