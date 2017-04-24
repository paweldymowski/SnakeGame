#include "border.h"
#include <QBrush>
#include <QColor>
#include <QGraphicsScene>
#include <QDebug>
#include <QPen>

Border::Border(){
    setRect(0,0,760,560);
    setPos(20,20);
    setBrush(QBrush(QColor(0,255,255,0)));
    //setPen(QColor(200,200,0,0));
    qDebug() << "border created";

}


