#ifndef SNAKEBODYPART_H
#define SNAKEBODYPART_H

#include <QGraphicsRectItem>
#include <QObject>
//#include <QDebug>
#include <QTimer>


class SnakeBodyPart: public QObject, public QGraphicsRectItem{

public:
    int direction;
    SnakeBodyPart(int x, int y);
    //QTimer * timer;

};



#endif // SNAKEBODYPART_H
