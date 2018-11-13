#include "Interface.h"
#include <QApplication>
#include <glut.h>
/*
 * 为了可以在回调函数中进行值的传输，和在所有类中共用变量，所以定义以下全局变量
 * 1：存储点云的QPointF类型的二维向量
 * 2：向量宽度
 * 3：向量长度
*/
//二维ProfilePoint向量，在获取到对应的length和width之后使用resize()重新定义大小
//存储高度图的向量
QVector <QVector<ProfilePoint> > _pointsVector;
k32u _pointVectorHeight = 0;
//高度向量长度宽度
int _vectorLength, _vectorWidth;
//存储亮度图数据
QVector <QVector<ProfilePoint> > _pointsVector_intensity;
//亮度向量长度宽度
int _vectorLength_intensity, _vectorWidth_intensity;
//存储UNIFORM图数据
QVector <QVector<ProfilePoint> > _pointsVector_uniform;
//UNIFORM向量长度宽度
int _vectorLength_uniform, _vectorWidth_uniform;
//图像的尺寸数据
int _x, _y;
//获取的测量结果
k64f measurement_vec[10];
//onData执行状态标识；
bool onData_ok = false;
bool Erroneous = false;
//等待窗口打印语句
QString print_string = "正在初始化传感器\n";
//五个线程分别从哪里开始
int t1, t2, t3, t4, t5;
//点数据
QVector<QVector<QPointF> > pfVec;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Interface w;
    w.move(550, 100);
    w.show();

    return a.exec();
}
