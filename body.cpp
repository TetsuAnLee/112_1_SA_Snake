#include "body.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
Body::Body()
{
    QPixmap pixmap(":/images/Pacman.png");
    pixmap = pixmap.scaled(50, 50); // 设置图像大小为50x50
    setPixmap(pixmap);
}
