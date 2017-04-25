#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QDebug>
#include <vector>
#include <utility>
#include <snakebodypart.h>

class SnakeHead: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    int direction;
    SnakeHead();
    std::vector<SnakeBodyPart*> snakeTail;
    void keyPressEvent(QKeyEvent * event);
    QTimer * timer = new QTimer();

public slots:
    void move();
    void updateTail();

};

#endif // SNAKEHEAD_H
