#include "food.h"

Food::Food()
{
    setPixmap(QPixmap(":../diet.png"));
    setPos(rand() % 700, rand() % 500);
}
