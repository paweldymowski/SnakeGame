#ifndef BORDER_H
#define BORDER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QDebug>

class Border: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Border();

};



#endif // BORDER_H