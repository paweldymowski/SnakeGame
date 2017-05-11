#include "snakehead.h"
#include "food.h"
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <iterator>
#include <directions.h>

SnakeHead::SnakeHead(){

    setPixmap(QPixmap(":/images/head.png"));
    setPos(100,100);
    setTransformOriginPoint(10, 10);
    snakeTail.push_back(new SnakeBodyPart(x() - 60, y()));
    snakeTail.push_back(new SnakeBodyPart(x() - 40, y()));
    snakeTail.push_back(new SnakeBodyPart(x() - 20, y()));

    foodEaten = false;
    keyPressed = false;
    direction = moveRight;


    qDebug() << "snakeHead created";
}

void SnakeHead::keyPressEvent(QKeyEvent *event)
{
    if (!keyPressed){
        if (event->key() == Qt::Key_Left && (direction != moveRight) && (direction != moveLeft)){
            direction = moveLeft;
            setRotation(-180);
            keyPressed = true;
            qDebug() << "direction changed";
        }
        else if (event->key() == Qt::Key_Right && (direction != moveLeft) && (direction != moveRight)){
            direction = moveRight;
            setRotation(0);
            keyPressed = true;
            qDebug() << "direction changed";
        }
        else if (event->key() == Qt::Key_Down && (direction != moveUp) && (direction != moveDown)){
            direction = moveDown;
            setRotation(90);
            keyPressed = true;
            qDebug() << "direction changed";
        }
        else if (event->key() == Qt::Key_Up && (direction != moveDown) && (direction != moveUp)){
            direction = moveUp;
            setRotation(-90);
            keyPressed = true;
            qDebug() << "direction changed";
        }
    }
}

void SnakeHead::updateTail(){

    if (!foodEaten) {

        std::vector<SnakeBodyPart*>::iterator it = snakeTail.begin();

        while (it != snakeTail.end()){

            if (it != snakeTail.end() - 1){
                (**it).setPos((**(it+1)).x(), (**(it+1)).y() );
                it++;
            }
            else {
                (**it).setPos(x(), y() );
                it++;
            }
        }
    }
    else{
        snakeTail.push_back(new SnakeBodyPart(x(), y()));
        std::vector<SnakeBodyPart*>::reverse_iterator it = snakeTail.rbegin();
        scene()->addItem(*it);
        foodEaten = false;
    }
}

void SnakeHead::move()
{
    updateTail();
    keyPressed = false;
     qDebug() << "direction change reset";

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
