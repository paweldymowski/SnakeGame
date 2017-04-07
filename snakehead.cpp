#include "snakehead.h"
#include <QKeyEvent>
#include <QTimer>
#include <QBrush>
#include <QColor>
#include <QGraphicsScene>
#include <QDebug>

SnakeHead::SnakeHead(){
    setRect(100,100,20,20);
    setBrush(QBrush(QColor(0,0,0,150)));

    direction = 2;

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(500);

}


void SnakeHead::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        this->direction = 4;
    }
    else if (event->key() == Qt::Key_Right){
        this->direction = 2;
    }
    else if (event->key() == Qt::Key_Down){
        this->direction = 3;
    }
    else if (event->key() == Qt::Key_Up){
        this->direction = 1;
    }
}

void SnakeHead::move()
{
    if (direction == 1){
        setPos(x(), y()-20);
    }
    else if (direction == 2){
        setPos(x()+20, y());
    }
    else if (direction == 3){
        setPos(x(), y()+20);
    }
    else if (direction == 4){
        setPos(x()-20, y());
    }

    if (pos().y() < -100 ||
        pos().y() > 100 ||
        pos().x() < -100 ||
        pos().x() > 100)

    {
        scene()->removeItem(this);
        delete this;
        qDebug() << pos().y() << "," << pos().x()  << "GAME OVER!";
    }

}
