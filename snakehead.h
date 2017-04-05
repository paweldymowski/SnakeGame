#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

#include <QGraphicsRectItem>
#include <QObject>

class SnakeHead: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    int direction;
    SnakeHead();
    void keyPressEvent(QKeyEvent * event);

public slots:
    void move();



};


#endif // SNAKEHEAD_H
