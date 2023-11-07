#ifndef SCENE_H
#define SCENE_H
#include "body.h"
#include "food.h"
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
    void collidesWithItem();
public slots:
    void forward();
private:
    bool gameOn;
    QList<Body*> head;
    Body *body;
    QTimer timer;
    Food * food;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event)override;
};

#endif // SCENE_H
