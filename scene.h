#ifndef SCENE_H
#define SCENE_H

#include "food.h"
#include "player.h"
#include "body.h"
#include <QGraphicsScene>
#include <QTimer>

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


private:
    bool gameOn;
    Player *player;
    QTimer *timer;
    Body *tail;


public slots:
    void spawnFood();
    void increaselong(Food *food);

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SCENE_H
