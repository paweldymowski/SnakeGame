#ifndef BORDER_H
#define BORDER_H

#include <QGraphicsRectItem>
#include <QObject>

/*! Draws border of the board. */

class Border: public QObject, public QGraphicsRectItem{

public:
    //! Constructor.
    /*!
      \param posX integer argument sets the position of Border on x axis
      \param posY integer argument sets the position of Border on y axis
      \param width integer argumen sets the width of Border
      \param height integer argument sets the heaight of Border
    */
    Border(int posX, int posY, int width, int height);
    //! Destructor.
    ~Border();
};

#endif // BORDER_H
