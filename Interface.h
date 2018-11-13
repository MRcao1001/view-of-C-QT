#ifndef INTERFACE_H
#define INTERFACE_H
#ifndef __APPLE__
#  include "halconcpp/HalconCpp.h"
#  include "halconcpp/HDevThread.h"
#  if defined(__linux__) && !defined(__arm__) && !defined(NO_EXPORT_APP_MAIN)
#    include <X11/Xlib.h>
#  endif
#else
#  ifndef HC_LARGE_IMAGES
#    include <HALCONCpp/HalconCpp.h>
#    include <HALCONCpp/HDevThread.h>
#  else
#    include <HALCONCppxl/HalconCpp.h>
#    include <HALCONCppxl/HDevThread.h>
#  endif
#  include <stdio.h>
#  include <HALCON/HpThread.h>
#  include <CoreFoundation/CFRunLoop.h>
#endif
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QPixmap>
#include <QPainter>
#include <QPen>
#include <QPointF>
#include <QMessageBox>
#include <QFileDialog>
#include "Sensor.h"
#include "Display.h"
#include "My_dailog.h"
#include "glwidget.h"
#include "glwindow.h"
extern "C"
{
    #include "GoSdk/GoSdk.h"
    #include "kApi/kApi.h"
}

using namespace HalconCpp;
class Interface : public QWidget
{
    Q_OBJECT

public:
    Interface(QWidget *parent = 0);
    ~Interface();
    //界面控件对象
    QPushButton *btn_start;
    QPushButton *btn_stop;
    QPushButton *btn_pause;
    QPushButton *btn_save;
    QPushButton *btn_next;
    QPushButton *btn_last;
    QLabel *list;
    QLabel *display;
    QLabel *tips;
    QPixmap pix;
    QPainter painter;
    QPen pen;
    //界面布局对象
    QVBoxLayout *main_area;
    QHBoxLayout *buttons;
    QHBoxLayout *display_area;
    QHBoxLayout *btn_area_top;
    QHBoxLayout *btn_area_bottom;
    QHBoxLayout *btn_area_last;
    QHBoxLayout *btn_area_start;
    QHBoxLayout *btn_area_pause;
    QHBoxLayout *btn_area_stop;
    QHBoxLayout *btn_area_next;
    QHBoxLayout *btn_area_save;
    QHBoxLayout *_main;
    //传感器对象
    Sensor *new_sensor;
    //显示对象
    Display *dp = NULL;
    my_Dailog *md;
//    glWindow *gw;
//    GLWidget *glw;
    //设置界面布局函数
    void layout_interface();
    //按钮和槽函数绑定函数
    void my_connect();
    //绘画函数
    void drawPic();

    //halcon生成的代码的函数声明
    void action();
    void showHalcon();
    // Local iconic variables
    HObject  ho_Image;
      // Local control variables
    HTuple  hv_AcqHandle, hv_WindowID;

public slots:
    void start_scan_btn_click();
    void pause_scan_btn_click();
    void stop_scan_btn_click();
    void next_pic_btn_click();
    void last_pic_btn_click();
    void save_pic_btn_click();

signals:
    void onData_ok_is_true();
};

#endif // INTERFACE_H
