#include "food.h"

Food::Food()
{
    QPixmap pixmap(":/images/homework.jpg");
    pixmap = pixmap.scaled(50, 50); // 设置图像大小为50x50
    setPixmap(pixmap);
    setPos(rand() % 700, rand() % 500);
}
Food::~Food(){
    delete this;
}
