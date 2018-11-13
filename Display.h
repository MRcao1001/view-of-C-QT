#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>
#include <QDebug>
#include <QVector>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QPixmap>
#include <QPainter>
#include <QPen>
#include <QPointF>
#include <QPalette>
#include <QApplication>
#include <QWheelEvent>
#include <QProgressDialog>
#include <QMessageBox>
#include "Profilepoint.h"
#include "Sensor.h"//在Sensor.h中申明了全局变量，在此引用

#define ASYBCHRONOUS 1;
#define SYNCHRONIZATION 0;
/*
 * 这个类存在的意义是
 * 当主界面获取到Sensor的数据时：点数组，数组长度，数组宽度
 * 会实例化这个类的对象，再该类的绘图事件函数中，根据获得的数据绘制图像到该窗口上
*/
class Display : public QWidget
{
    Q_OBJECT
public:
    //构造函数--使用异步图形处理方式时使用该方法
    Display(QWidget *parent = 0, int type = 0);
    //构造函数--使用同步图像处理方式使用该方法
    Display(QWidget *parent = 0, ProfilePoint **surfaceBuffer = NULL, int length = 0, int width = 0);
    //同步图像处理数据转化函数
    void get_data(int type);
    //界面布局函数
    void layout_interface();
    //重载绘图事件
    void paintEvent(QPaintEvent *ev);
    //重载滚轮事件
    void wheelEvent(QWheelEvent *event);
    //鼠标点击事件
    bool event(QEvent *event);
    //绘制图形函数
    void my_draw();

    //控件对象
    QLabel *back_ground;
    QVBoxLayout *back_layout;
    QPixmap *pixmap;
    QPainter painter;
    //数据对象
    ProfilePoint **PointBuffer;
    int picLength, picntWidth, m_type;
    double ratio = 1;//缩放比例
    int action = -1;//动作事件
    QPoint offset;//一次偏移量
    QPoint Alloffset;//总偏移量
    int x_top = 0;
    int y_top = 0;
//    QVector<QVector<QPointF> > pfVec;//点数据
signals:

public slots:
    //多线程绘制函数
    void drawInThread(QPixmap *pix, int y);
};

#endif // DISPLAY_H
