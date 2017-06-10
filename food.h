#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsPixmapItem>
#include <QObject>

/*! Food for snake representead as 20px x 20px image of an apple on the board. */

class Food: public QObject, public QGraphicsPixmapItem {

public:
    //! Constructor.
    Food();
    //! Destructor.
    ~Food();
};

#endif // FOOD_H
