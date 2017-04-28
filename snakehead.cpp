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
#include <directions.h>

SnakeHead::SnakeHead(){

    //setRect(0,0,20,20);
    setPixmap(QPixmap(":/images/head.png"));
    setPos(100,100);
    setTransformOriginPoint(10, 10);
    snakeTail.push_back(new SnakeBodyPart(x() - 60, y()));
    snakeTail.push_back(new SnakeBodyPart(x() - 40, y()));
    snakeTail.push_back(new SnakeBodyPart(x() - 20, y()));

    direction = moveRight;

    qDebug() << "snakeHead created";

}

void SnakeHead::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left && (this->direction != moveRight) ){
        //if (direction == moveUp) setRotation(-90);
        //else if (direction == moveDown) setRotation(90);
        this->direction = moveLeft;
        setRotation(-180);
    }
    else if (event->key() == Qt::Key_Right && (this->direction != moveLeft) ){
        //if (direction == moveUp) setRotation(90);
        //else if (direction == moveDown) setRotation(-90);
        this->direction = moveRight;
        setRotation(0);
    }
    else if (event->key() == Qt::Key_Down && (this->direction != moveUp) ){
        //if (direction == moveRight) setRotation(90);
        //else if (direction == moveLeft) setRotation(-90);
        this->direction = moveDown;
        setRotation(90);
    }
    else if (event->key() == Qt::Key_Up && (this->direction != moveDown) ){
        //if (direction == moveLeft) setRotation(-90);
        //else if (direction == moveRight) setRotation(90);
        this->direction = moveUp;
        setRotation(-90);
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

    if (direction == moveUp){
        setPos(x(), y()-20);
    }
    else if (direction == moveRight){
        setPos(x()+20, y());
    }
    else if (direction == moveDown){
        setPos(x(), y()+20);
    }
    else if (direction == moveLeft){
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
