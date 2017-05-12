#include <game.h>
#include <food.h>
#include <snakehead.h>
#include <snakebodypart.h>
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsTextItem>
#include <string>

Game::Game(){

    scene = new QGraphicsScene();

    snakeHead = new SnakeHead();
    food = new Food();
    border = new Border();
    gamePaused = false;
    scores = 0;
    scoreViewer = new QGraphicsTextItem();
    scoreViewer->setPos(0, 0);
    scoreViewer->setPlainText(QString::number(scores));

    scene->addItem(scoreViewer);

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

void Game::gamePause(){

    if (!gamePaused){
        timer->blockSignals(true);
        gamePaused = true;
        qDebug() << "game paused";
    }
    else {
        timer->blockSignals(false);
        gamePaused = false;
        qDebug() << "game restarted";
    }
}

void Game::foodEaten(){

     if (food->pos() == snakeHead->pos()){
        qDebug() << "food eaten";
        snakeHead->foodEaten = true;
        scene->removeItem(food);
        createNewFood();
        scores += 10;
        scoreViewer->setPlainText(QString::number(scores));
        timer->setInterval(timer->interval() * 0.9); // snake speed increases by 10%
        qDebug() << "news speed = " << timer->interval() ;
    }
}

void Game::createNewFood(){

    food = new Food();
    scene->addItem(food);
    qDebug() << "new food created";
}
