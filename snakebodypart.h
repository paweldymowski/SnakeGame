#ifndef SNAKEBODYPART_H
#define SNAKEBODYPART_H

#include <QGraphicsPixmapItem>
#include <QObject>

/*! Part of snake tail. */

class SnakeBodyPart: public QObject, public QGraphicsPixmapItem{

public:
     //! Constructor.
    /*!
      \param posX integer argument sets the position of SnakeBodyPart on x axis
      \param posY integer argument sets the position of SnakeBodyPart on y axis
    */
     SnakeBodyPart(int posX, int posY);
     //! Destructor.
    ~SnakeBodyPart();
};

#endif // SNAKEBODYPART_H
