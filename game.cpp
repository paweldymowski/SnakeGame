#include <game.h>
#include <food.h>
#include <snakehead.h>
#include <snakebodypart.h>
#include <QDebug>


Game::Game(){

    scene = new QGraphicsScene();

    snakeHead = new SnakeHead();
    food = new Food();
    border = new Border();

    scene->addItem(snakeHead);
    scene->addItem(food);
    scene->addItem(border);

    std::vector<SnakeBodyPart*>::iterator it = snakeHead->snakeTail.begin();

    while (it != snakeHead->snakeTail.end()){
        scene->addItem(*it);
        it++;
    }
    qDebug() << "snake body parts added to scene";
}

void Game::foodEaten(){

    if (food->pos() == snakeHead->pos()){
        qDebug() << "food eaten";
        snakeHead->foodEaten = true;
        scene->removeItem(food);
        for (int i = 0; i < 100; i++){
            createNewFood();
        }
        timer->setInterval(timer->interval()-50);
    }
}

void Game::createNewFood(){

    food = new Food();
    scene->addItem(food);
    qDebug() << "new food created";
}
