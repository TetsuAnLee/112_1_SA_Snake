#ifndef SCENE_H
#define SCENE_H

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
};

#endif // SCENE_H
