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

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(200,200);

    scene->setSceneRect(0,0,200,200);

    return a.exec();
}
