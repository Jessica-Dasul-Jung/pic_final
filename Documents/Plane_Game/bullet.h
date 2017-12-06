#ifndef BULLET_H
#define BULLET_H

#include "globals.h"

class Bullet: public QObject, public QGraphicsRectItem
{
public:
    Bullet();
    Q_OBJECT
    virtual ~Bullet();

public slots:
    void move();

private:
    QTimer* m_timer;
};

#endif // BULLET_H
