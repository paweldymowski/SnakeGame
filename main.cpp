#include <QApplication>
#include <QGraphicsScene>
#include <snakehead.h>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();

    SnakeHead * snakeHead = new SnakeHead();

    scene->addItem(snakeHead);

    snakeHead->setFlag(QGraphicsItem::ItemIsFocusable);
    snakeHead->setFocus();

    QGraphicsView * view = new QGraphicsView(scene);

    view->show();
    view->setFixedSize(800,600);

    scene->setSceneRect(0,0,800,600);

    return a.exec();
}
