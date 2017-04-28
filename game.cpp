#include <game.h>
#include <food.h>
#include <snakehead.h>
#include <snakebodypart.h>
#include <QDebug>

void Game::foodEaten(){

    if (food->pos() == snakeHead->pos()){
        qDebug() << "food eaten";
        snakeHead->foodEaten = true;
        scene->removeItem(food);
        createNewFood();
        timer->setInterval(timer->interval()-50);
    }
}

void Game::createNewFood(){

    food = new Food();
    scene->addItem(food);
    qDebug() << "new food created";
}
