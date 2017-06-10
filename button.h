#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

/*! Menu buttons. */

class Button:public QObject, public QGraphicsRectItem{
    Q_OBJECT

public:
    //! Constructor.
    Button(QString name, QGraphicsItem * parent=NULL);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
    //! Destructor.
    ~Button();

signals:
    void clicked();

private:
    QGraphicsTextItem * text;

};

#endif // BUTTON_H
