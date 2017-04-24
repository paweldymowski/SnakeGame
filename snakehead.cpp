#include "snakehead.h"
#include <QKeyEvent>
#include <QTimer>
#include <QBrush>
#include <QColor>
#include <QGraphicsScene>
#include <QDebug>

SnakeHead::SnakeHead(){

    setRect(0,0,20,20);
    setPos(100,100);
    setBrush(QBrush(QColor(255,0,0,0)));

    //snakeTail.push(std::make_pair(pos().x(), pos().y()));
    //snakeTail.push(std::make_pair(pos().x() - 20, pos().y()));
    //snakeTail.push(std::make_pair(pos().x() - 40, pos().y()));

    direction = 2;

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(500);
    qDebug() << "snakeHead created";

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

    if (pos().y() < 20 ||
        pos().y() > 560 ||
        pos().x() < 20 ||
        pos().x() > 760)

    {
        scene()->removeItem(this);
        delete this;
        qDebug() << pos().y() << "," << pos().x()  << "GAME OVER!";
    }
    qDebug() << "snake moved";

}
