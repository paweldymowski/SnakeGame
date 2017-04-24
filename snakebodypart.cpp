#include "snakebodypart.h"
#include <QKeyEvent>
#include <QTimer>
#include <QBrush>
#include <QColor>
#include <QGraphicsScene>
#include <QDebug>

SnakeBodyPart::SnakeBodyPart(int x, int y, int dir){

    setRect(0,0,20,20);
    setPos(x, y);
    setBrush(QBrush(QColor(255,0,255,155)));

    direction = dir;

    qDebug() << "snakeBodyPart created";

}




