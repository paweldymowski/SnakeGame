#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Food: public QObject, public QGraphicsPixmapItem {

public:
    Food();
    ~Food();
};

#endif // FOOD_H
