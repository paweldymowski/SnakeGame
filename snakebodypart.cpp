#include "snakebodypart.h"
#include <QKeyEvent>
#include <QTimer>
#include <QBrush>
#include <QColor>
#include <QGraphicsScene>
#include <QDebug>
#include <QPixmap>

SnakeBodyPart::SnakeBodyPart(int x, int y){

    setPixmap(QPixmap(":/images/test.png"));
    setPos(x, y);

    qDebug() << "snakeBodyPart created";

}




