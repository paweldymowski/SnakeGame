#include "snakebodypart.h"
#include <QKeyEvent>
#include <QTimer>
#include <QBrush>
#include <QColor>
#include <QGraphicsScene>
#include <QDebug>

SnakeBodyPart::SnakeBodyPart(int x, int y){

    setRect(0,0,20,20);
    setPos(x, y);
    setBrush(QBrush(QColor(100,0,100,155)));

    qDebug() << "snakeBodyPart created";

}




