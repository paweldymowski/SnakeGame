#include <game.h>
#include <food.h>
#include <snakehead.h>
#include <snakebodypart.h>
#include <QDebug>


void Game::foodEaten(){

    if (food->pos() == snakeHead->pos()){
        qDebug() << "food eaten!";
        snakeHead->foodEaten = true;
    }

}

void Game::makeNewSnakePartVisible(){

    std::vector<SnakeBodyPart*>::reverse_iterator it = snakeHead->snakeTail.rbegin();
    scene->addItem(*it);
    qDebug() << "elementy dodane";

}
