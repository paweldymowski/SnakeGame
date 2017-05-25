#ifndef SNAKEBODYPART_H
#define SNAKEBODYPART_H

#include <QGraphicsPixmapItem>
#include <QObject>

class SnakeBodyPart: public QObject, public QGraphicsPixmapItem{

public:
    SnakeBodyPart(int posX, int posY);
};

#endif // SNAKEBODYPART_H
