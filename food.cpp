#include "food.h"
#include <QBrush>
#include <QColor>
#include <QGraphicsScene>
#include <QDebug>
#include <QPen>

Food::Food(){
    static std::random_device generator;
    std::uniform_int_distribution<int> distribution(1,38);
    std::uniform_int_distribution<int> distribution2(1,28);
    int randomNumber1 = distribution(generator) * 20;
    int randomNumber2 = distribution2(generator) * 20;
    setRect(0,0,20,20);
    setPos(randomNumber1,randomNumber2);
    setBrush(QBrush(QColor(0,255,255,0)));
    //setPen(QColor(200,200,0,0));
    qDebug() << "food created on position " << randomNumber1 << " x " << randomNumber2;

}


