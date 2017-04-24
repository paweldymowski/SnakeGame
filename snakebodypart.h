#ifndef SNAKEBODYPART_H
#define SNAKEBODYPART_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QDebug>


class SnakeBodyPart: public QObject, public QGraphicsRectItem{

public:
    int direction;
    SnakeBodyPart(int x, int y, int dir);

};



#endif // SNAKEBODYPART_H
