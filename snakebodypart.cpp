#include "snakebodypart.h"
#include <QDebug>
#include <QPixmap>

SnakeBodyPart::SnakeBodyPart(int posX, int posY){

    setPixmap(QPixmap(":/images/test.png"));
    setPos(posX, posY);

    qDebug() << "snakeBodyPart created";

}




