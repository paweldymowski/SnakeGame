#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();

    QGraphicsRectItem * rect = new QGraphicsRectItem();
    rect->setRect(0,0, 20, 20);

    scene->addItem(rect);

    QGraphicsView * view = new QGraphicsView(scene);

    view->show();




    return a.exec();
}
