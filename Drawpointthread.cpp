#include "Drawpointthread.h"

DrawPointThread::DrawPointThread(QObject *parent) : QObject(parent)
{
}

DrawPointThread::~DrawPointThread()
{

}

void DrawPointThread::drawPoint()
{
    pixmap = new QPixmap(_x,_y);
    //设置画布为黑色
    pixmap->fill(Qt::blue);
    QPainter painter;
    //在pixmap(画布)上绘图, 附带重置属性
    if(painter.begin(pixmap) == false){qDebug()<<"error";}
    //申明并初始化画笔
    QPen pen1(Qt::red,1,Qt::DashLine,Qt::FlatCap,Qt::RoundJoin);
    //显示亮度图

    int gray = 0;
    for(int i=0; i< _vectorLength_intensity; i++){
        for(int j=0; j < _vectorWidth_intensity; j++){
            gray = _pointsVector_intensity[i][j].intensity;
            //qDebug()<<gray;
            pen1.setColor(QColor(gray, gray, gray));
            painter.setPen(pen1);
            painter.drawPoint(pfVec[i][j]);
        }
    }
    painter.end();
    emit drawPointDone(pixmap);
}

