#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QDebug>
#include <queue>
#include <utility>

class SnakeHead: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    int direction;
    SnakeHead();
    std::queue<std::pair<int,int>> snakeTail;
    void keyPressEvent(QKeyEvent * event);

public slots:
    void move();

};

#endif // SNAKEHEAD_H
