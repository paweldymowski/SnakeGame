#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QDebug>
#include <vector>
#include <utility>
#include <snakebodypart.h>
#include <food.h>

class SnakeHead: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    int direction;
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
