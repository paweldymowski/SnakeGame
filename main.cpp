#include <QApplication>
#include <QGraphicsScene>
#include <snakehead.h>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();

    SnakeHead * rect = new SnakeHead();
    rect->setRect(0,0, 20, 20);

    scene->addItem(rect);

    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    QGraphicsView * view = new QGraphicsView(scene);

    view->show();




    return a.exec();
}
