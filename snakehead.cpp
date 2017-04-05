#include "snakehead.h"
#include <QKeyEvent>

void SnakeHead::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        setPos(x()-20, y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+20, y());
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(), y()+20);
    }
    else if (event->key() == Qt::Key_Up){
        setPos(x(), y()-20);
    }
}
