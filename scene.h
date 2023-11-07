#ifndef SCENE_H
#define SCENE_H
#include "body.h"
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
public slots:
    void forward();
private:
    bool gameOn;
    QList<Body*> head;
    Body *body;
    QTimer timer;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SCENE_H
