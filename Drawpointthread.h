#ifndef DRAWPOINTTHREAD_H
#define DRAWPOINTTHREAD_H

#include <QObject>
#include <QMutex>
#include <QPixmap>
#include <QPainter>
#include <QPen>
#include "Display.h"
class DrawPointThread : public QObject
{
    Q_OBJECT
public:
    DrawPointThread(QObject *parent = nullptr);
    ~DrawPointThread();
    QPixmap *pixmap;
signals:
    void drawPointDone(QPixmap *m_pixmap);

public slots:
    void drawPoint();
};

#endif // DRAWPOINTTHREAD_H
