#include <QApplication>
#include <QGraphicsScene>
#include <snakehead.h>
#include <snakebodypart.h>
#include <border.h>
#include <food.h>
#include <QGraphicsView>
#include <QDebug>
#include <vector>

int main(int argc, char *argv[])
{

    qDebug() << "test";

    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();

    SnakeHead * snakeHead = new SnakeHead();
    Border * border = new Border();
    Food * food = new Food();


    scene->addItem(snakeHead);
    scene->addItem(border);
    scene->addItem(food);

    //std::vector<SnakeBodyPart*> snakeBody;
    //snakeBody.push_back(new SnakeBodyPart((int)snakeHead->snakeTail.front().first, (int)snakeHead->snakeTail.front().second, 2 ));
    //snakeBody.push_back(new SnakeBodyPart((int)snakeHead->snakeTail.front().first, (int)snakeHead->snakeTail.front().second, 2 ));
    //scene->addItem(snakeBody[0]);
    //scene->addItem(snakeBody[1]);


    snakeHead->setFlag(QGraphicsItem::ItemIsFocusable);
    snakeHead->setFocus();

    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800,600);

    scene->setSceneRect(0,0,800,600);

    return a.exec();
}
