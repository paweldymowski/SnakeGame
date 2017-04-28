#include "border.h"
#include <QBrush>
#include <QColor>
#include <QDebug>


Border::Border(){
    setRect(0,0,760,560);
    setPos(20,20);
    setBrush(QBrush(QColor(0,255,255,0)));
    qDebug() << "border created";

}


