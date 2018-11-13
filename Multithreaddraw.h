#ifndef MULTITHREADDRAW_H
#define MULTITHREADDRAW_H
#include <QThread>
#include <QPointF>
#include <QPixmap>
#include <QVector>
#include <QMessageBox>
#include <QPainter>
#include <QPen>
#include <QProgressDialog>
#include <QApplication>
#include "Sensor.h"
//创建五个此线程来执行渲染操作，分别传入要绘制的向量，从哪一行开始绘制，绘制到何处
class MultiThreadDraw : public QThread
{
        Q_OBJECT
public:
    MultiThreadDraw(int _temp);
    QPixmap *pix;
    QPainter painter;
    int temp;
protected:
    void run();

public slots:
    void start_draw();
signals:
    void send_pixmap(QPixmap *_pixmap, int y);
private:
    volatile int start_export;
};

#endif // MULTITHREADDRAW_H
