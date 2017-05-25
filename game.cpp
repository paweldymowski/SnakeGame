#include <game.h>
#include <food.h>
#include <snakehead.h>
#include <snakebodypart.h>
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsTextItem>
#include <string>
#include <QGraphicsView>
#include <QTimer>

Game::Game(){

    scene = new QGraphicsScene();

    snakeHead = new SnakeHead();

    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    boardWidth = 800;
    boardHeight = 600;
    gameObiectsSize = 20;
    view->setFixedSize(boardWidth, boardHeight);

    scene->setSceneRect(0, 0,boardWidth, boardHeight);
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), snakeHead, SLOT(move()));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(foodEaten()));
    QObject::connect(snakeHead, SIGNAL(spacePressed()), this, SLOT(gamePause()));

    food = new Food();
    border = new Border(gameObiectsSize, gameObiectsSize, boardWidth - 40, boardHeight - 40);
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

void Game::startGame(int gameSpeed){
    timer->start(gameSpeed);
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
