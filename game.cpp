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
#include <button.h>

Game::Game(){

    scene = new QGraphicsScene();

    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    boardWidth = 800;
    boardHeight = 600;
    gameObiectsSize = 20;
    scoresForFood = 10;
    firstGame = true;
    view->setFixedSize(boardWidth, boardHeight);

    scene->setSceneRect(0, 0,boardWidth, boardHeight);
    gamePaused = false;

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

void Game::startGame(){
    scene->clear();
    firstGame = false;
    snakeHead = new SnakeHead();
    timer = new QTimer();
    food = new Food();
    border = new Border(gameObiectsSize, gameObiectsSize, boardWidth - 40, boardHeight - 40);
    scoreViewer = new QGraphicsTextItem();
    scores = 0;
    scene->addItem(snakeHead);
    scene->addItem(food);

    scoreViewer->setPos(0, 0);
    scoreViewer->setPlainText(QString::number(scores));

    scene->addItem(scoreViewer);
    scene->addItem(border);

    std::vector<SnakeBodyPart*>::iterator it = snakeHead->snakeTail.begin();

    while (it != snakeHead->snakeTail.end()){
        scene->addItem(*it);
        it++;
    }
    qDebug() << "snake body parts added to scene";
    QObject::connect(timer, SIGNAL(timeout()), snakeHead, SLOT(move()));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(foodEaten()));
    QObject::connect(snakeHead, SIGNAL(spacePressed()), this, SLOT(gamePause()));
    QObject::connect(snakeHead, SIGNAL(snakeIsDead()), this, SLOT(displayMenu()));
    QObject::connect(snakeHead, SIGNAL(snakeIsDead()), this, SLOT(clearGame()));

    timer->start(500);
    qDebug() << "nowa gra rozpoczeta";
}

void Game::clearGame(){
    delete timer;
    delete snakeHead;
    delete food;
    delete border;
    delete scoreViewer;

    qDebug() << "stara gra wyczyszczona";
}

void Game::displayMenu(){

    QString text = "Snake";

    if(!firstGame){
        text = QString("Game Over! Score: %1").arg(scores);
    }

    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString(text));
    QFont titleFont("arial", 30);
    titleText->setFont(titleFont);
    int txPos = boardWidth/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos, tyPos);
    scene->addItem(titleText);

    Button * playButton = new Button(QString("Play"));
    int bxPos = boardWidth/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos, byPos);
    QObject::connect(playButton, SIGNAL(clicked()), this, SLOT(startGame()));
    scene->addItem(playButton);

    Button * quitButton = new Button(QString("Quit"));
    int qxPos = boardWidth/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos, qyPos);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);

    qDebug() << "menu wyswietlone";
}

void Game::foodEaten(){

     if (food->pos() == snakeHead->pos()){
        qDebug() << "food eaten";
        snakeHead->foodEaten = true;
        scene->removeItem(food);
        createNewFood();
        scores += scoresForFood;
        scoreViewer->setPlainText(QString::number(scores));
        timer->setInterval(timer->interval() * 0.9); // snake speed increases by 10%
        qDebug() << "news speed = " << timer->interval() ;
    }
}

void Game::createNewFood(){

    food = new Food();
    scene->addItem(food);
}

void Game::close(){
    qDebug() << "game closed" ;
    exit(0);
}
