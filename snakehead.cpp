#include "snakehead.h"
#include <QKeyEvent>
#include <QTimer>
#include <QBrush>
#include <QColor>
#include <QGraphicsScene>
#include <QDebug>

SnakeHead::SnakeHead(){
    setRect(400,300,40,40);
    setBrush(QBrush(QColor(0,0,0,150)));

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

int direction = 1;

void SnakeHead::move()
{
    if (direction == 1){
        setPos(x(), y()-40);
    }
    else if (direction == 2){
        setPos(x()+40, y());
    }
    else if (direction == 3){
        setPos(x(), y()+40);
    }
    else if (direction == 4){
        setPos(x()-40, y());
    }

    if (pos().y() < -400 ||
        pos().y() > 400 ||
        pos().x() < -300 ||
        pos().x() > 300)

    {
        scene()->removeItem(this);
        delete this;
        qDebug() << pos().y() << "GAME OVER!";
    }

}
