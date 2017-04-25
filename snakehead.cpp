#include "snakehead.h"
#include "food.h"
#include <QKeyEvent>
#include <QTimer>
#include <QBrush>
#include <QColor>
#include <QGraphicsScene>
#include <QDebug>
#include <typeinfo>
#include <iterator>

SnakeHead::SnakeHead(){

    setRect(0,0,20,20);
    setPos(100,100);
    setBrush(QBrush(QColor(255,0,0,0)));

    snakeTail.push_back(new SnakeBodyPart(x() - 60, y()));
    snakeTail.push_back(new SnakeBodyPart(x() - 40, y()));
    snakeTail.push_back(new SnakeBodyPart(x() - 20, y()));

    direction = 2;

    qDebug() << "snakeHead created";

}

void SnakeHead::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left && (this->direction != 2) ){
        qDebug() << "direction changed from: " << this->direction << " to 4";
        this->direction = 4;
    }
    else if (event->key() == Qt::Key_Right && (this->direction != 4) ){
        qDebug() << "direction changed from: " << this->direction << " to 2";
        this->direction = 2;
    }
    else if (event->key() == Qt::Key_Down && (this->direction != 1) ){
        qDebug() << "direction changed from: " << this->direction << " to 3";
        this->direction = 3;
    }
    else if (event->key() == Qt::Key_Up && (this->direction != 3) ){
        qDebug() << "direction changed from: " << this->direction << " to 1";
        this->direction = 1;
    }
}
void SnakeHead::updateTail(){

    if (!foodEaten) {

        std::vector<SnakeBodyPart*>::iterator it = snakeTail.begin();

        while (it != snakeTail.end()){

            if (it != snakeTail.end() - 1){
                (**it).setPos((**(it+1)).x(), (**(it+1)).y() );
                it++;
                qDebug() << "body part updated from x: " << (**it).x() << " y: " << (**it).y();
                //qDebug() << "to x: " << (**(it+1)).x() << " y: " << (**(it+1)).y();
            }
            else {
                (**it).setPos(x(), y() );
                //qDebug() << "last body part updated from x: " << (**it).x() << " y: " << (**it).y();
                //qDebug() << "to x: " << x() << " y: " << y();
                it++;
            }
        }
    }
    else{
        snakeTail.push_back(new SnakeBodyPart(x(), y()));
        foodEaten = false;


    }
}

void SnakeHead::move()
{
    updateTail();

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
        qDebug() << pos().y() << "," << pos().x()  << "GAME OVER! Snake hit wall!";
    }

    std::vector<SnakeBodyPart*>::iterator it = snakeTail.begin();

    while (it != snakeTail.end()){
        if ((**it).pos() == pos() ){
            scene()->removeItem(this);
            delete this;
            qDebug() << "GAME OVER! Snake hit own body!";
            break;
        };
        it++;

    }


    qDebug() << "head moved";

}
