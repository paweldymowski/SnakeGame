#include <QApplication>
#include <QGraphicsScene>
#include <snakehead.h>
#include <snakebodypart.h>
#include <border.h>
#include <food.h>
#include <QGraphicsView>
#include <QDebug>
#include <vector>
#include <utility>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();

    SnakeHead * snakeHead = new SnakeHead();
    Border * border = new Border();
    Food * food = new Food();

    scene->addItem(snakeHead);
    scene->addItem(border);
    scene->addItem(food);

    std::vector<SnakeBodyPart*>::iterator it = snakeHead->snakeTail.begin();

    while (it != snakeHead->snakeTail.end()){
        scene->addItem(*it);
        it++;
    }
    qDebug() << "elementy dodane";

    snakeHead->setFlag(QGraphicsItem::ItemIsFocusable);
    snakeHead->setFocus();

    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800,600);

    scene->setSceneRect(0,0,800,600);
    //snakeHead->timer->start(1000);

    return a.exec();
}
