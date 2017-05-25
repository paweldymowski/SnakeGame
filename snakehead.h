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
    SnakeHead();
    directions direction;
    bool foodEaten;
    bool keyPressed;
    void keyPressEvent(QKeyEvent * event);
    void updateTail();
    void makeNewSnakePartVisible();
    std::vector<SnakeBodyPart*> snakeTail;

public slots:
    void move();
signals:
    void spacePressed();
};

#endif // SNAKEHEAD_H
