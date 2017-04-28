#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QDebug>
#include <QLabel>


class Food: public QObject, public QGraphicsPixmapItem {


public:
    Food();
    QLabel label;

};


#endif // FOOD_H
