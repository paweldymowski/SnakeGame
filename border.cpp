#include "border.h"
#include <QDebug>

Border::Border(int posX, int posY, int width, int height){
    setRect(0, 0, width, height);
    setPos(posX, posY);
    qDebug() << "border created";
}


