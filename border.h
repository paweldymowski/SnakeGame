#ifndef BORDER_H
#define BORDER_H

#include <QGraphicsRectItem>
#include <QObject>

class Border: public QObject, public QGraphicsRectItem{

public:
    Border(int posX, int posY, int width, int height);
};

#endif // BORDER_H
