#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QDebug>
#include <vector>
#include <utility>
#include <snakebodypart.h>
#include <food.h>
#include <directions.h>

class SnakeHead: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    directions direction;
    bool foodEaten = false;
    SnakeHead();
    std::vector<SnakeBodyPart*> snakeTail;
    void keyPressEvent(QKeyEvent * event);
    void updateTail();
    void makeNewSnakePartVisible();

public slots:
    void move();
};

#endif // SNAKEHEAD_H
