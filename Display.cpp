#include "Display.h"
//图像显示

//构造函数
Display::Display(QWidget *parent, int type)
    : QWidget(parent)
{
    qDebug()<<"!!!";
    get_data(1);
    m_type = type;
    layout_interface();
}

//构造函数2
Display::Display(QWidget *parent,  ProfilePoint **surfaceBuffer, int length, int width)
    : QWidget(parent)
{
    PointBuffer = surfaceBuffer;
    picLength = length;
    picntWidth = width;
    get_data(0);
    layout_interface();
}

//界面样式设定
void Display::layout_interface()
{
    this->setFixedSize(720,680);
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::black); //设置背景黑色
    this->setAutoFillBackground(true);
    this->setPalette(pal);}

//将获取到的数据进行优化并转化为QPointF类型的点
void Display::get_data(int type)
{

//        double x_offset = _pointsVector_uniform[0][0].x;
//        double y_offset = _pointsVector_uniform[0][0].y;
//        int zoom = 0;
//        //确定缩放倍数
//        for(zoom; zoom<100; zoom++){
//            if((_pointsVector_uniform[_vectorLength_uniform-1][_vectorWidth_uniform-1].x - x_offset) * zoom < 700
//                    &&(_pointsVector_uniform[_vectorLength_uniform-1][_vectorWidth_uniform-1].x - x_offset)  * zoom > 600){
//                break;
//            }
//        }
//        //将缩放倍数应用到点
//         pfVec.resize(_vectorLength_uniform);
//        for(int i = 0; i <_vectorLength_uniform; i++){
//            pfVec[i].resize(_vectorWidth_uniform);
//            for(int j = 0; j < _vectorWidth_uniform; j++){
//                pfVec[i][j].setX((_pointsVector_uniform[i][j].x-x_offset)*zoom+40);
//                pfVec[i][j].setY((_pointsVector_uniform[i][j].y-y_offset)*zoom+100);
//            }
//        }

        //测试：获取亮度和坐标
    double x_offset = _pointsVector_intensity.at(0).at(0).x;
    double y_offset = _pointsVector_intensity.at(0).at(0).y;
//    qDebug()<<_pointsVector_intensity.at(0).at(0).intensity;
    int zoom = 3;
    qDebug()<<_pointsVector_intensity.size()<<_pointsVector_intensity[0].end()->intensity;
//    for(zoom; zoom<100; zoom++){
//        if((_pointsVector_intensity.at(_vectorLength_intensity-1).at(_vectorWidth_intensity-1).x - x_offset) * zoom < 700
//                &&(_pointsVector_intensity.at(_vectorLength_intensity-1).at(_vectorWidth_intensity-1).x  - x_offset)  * zoom > 600
//                &&(_pointsVector_intensity.at(_vectorLength_intensity-1).at(_vectorWidth_intensity-1).y  - y_offset)  * zoom > 200
//                &&(_pointsVector_intensity.at(_vectorLength_intensity-1).at(_vectorWidth_intensity-1).y  - y_offset)  * zoom < 400){
//            break;
//        }
//    }
    //确定位置


    _x = (_pointsVector_intensity[_vectorLength_intensity-1][_vectorWidth_intensity-1].x-x_offset)*zoom;
    _y = (_pointsVector_intensity[_vectorLength_intensity-1][_vectorWidth_intensity-1].y-y_offset)*zoom;
    pfVec.resize(_vectorLength_intensity);
    for(int i = 0; i <_vectorLength_intensity; i++){
        pfVec[i].resize(_vectorWidth_intensity);
        for(int j = 0; j < _vectorWidth_intensity; j++){
            pfVec[i][j].setX((_pointsVector_intensity[i][j].x-x_offset)*zoom);
            pfVec[i][j].setY((_pointsVector_intensity[i][j].y-y_offset)*zoom);
            if(_pointsVector_intensity[i][j].intensity !=0){
            }
        }
    }

//    pixmap = new QPixmap(_x,_y);
//    _x = (_pointsVector_intensity[_vectorLength_intensity-1][_vectorWidth_intensity-1].x-x_offset)*zoom;
//    _y = (_pointsVector_intensity[_vectorLength_intensity-1][_vectorWidth_intensity-1].y-y_offset)*zoom;
//    public_pVec.resize(_vectorLength_intensity);
//    for(int i = 0; i <_vectorLength_intensity; i++){
//        public_pVec[i].resize(_vectorWidth_intensity);
//        for(int j = 0; j < _vectorWidth_intensity; j++){
//            public_pVec[i][j].setX((_pointsVector_intensity[i][j].x-x_offset)*zoom);
//            public_pVec[i][j].setY((_pointsVector_intensity[i][j].y-y_offset)*zoom);
//            if(_pointsVector_intensity[i][j].intensity !=0){
//            }
//        }
//    }
}

//重写的绘图事件，调用drawpoint和drawoixmap方法将图像显示到界面上
void Display::paintEvent(QPaintEvent *ev)
{
    QPainter _p(this);
    _p.drawPixmap(x_top, y_top, _x*ratio, _y*ratio, *pixmap);

}

//重写鼠标滑轮事件
void Display::wheelEvent(QWheelEvent *event)
{
    if (event->delta()<0) {      //下滑,放大

       action=0;
       ratio -= 0.1;
       if(ratio <= 0)
           ratio =0.1;
       this->update();

    } else if(event->delta()>0) {                    //上滑,缩小
        action=1;
        ratio += 0.1;
        if(ratio >= 5)
            ratio =5;
        this->update();
    }

    event->accept();
}

//重写鼠标单击拖动事件
bool Display::event(QEvent *event)
{
    static bool press=false;
    static QPoint PreDot;

    if(event->type() == QEvent::MouseButtonPress )
    {
        QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);

        //判断鼠标是否是左键按下,且鼠标位置是否在绘画区域
        if(mouse->button()==Qt::LeftButton)
        {
            press=true;
            //QApplication::setOverrideCursor(Qt::OpenHandCursor); //设置鼠标样式
            this->setCursor(Qt::OpenHandCursor);

            PreDot = mouse->pos();
        }

    }
    else if(event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);

        //判断鼠标是否是左键释放,且之前是在绘画区域
        if(mouse->button()==Qt::LeftButton && press )
        {
            //QApplication::setOverrideCursor(Qt::ArrowCursor); //改回鼠标样式
            this->setCursor((Qt::ArrowCursor));
            press=false;
        }
    }

    if(event->type() == QEvent::MouseMove)              //移动图片
    {
        if(press)
        {
            QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);

            offset.setX(mouse->x() - PreDot.x());
            offset.setY(mouse->y() - PreDot.y());
            x_top = x_top+=offset.x();
            y_top = y_top+=offset.y();
            PreDot = mouse->pos();
            action = 2;
            this->update();
        }
    }
    return QWidget::event(event);
}

//绘制图像主函数
void Display::my_draw()
{
    pixmap = new QPixmap(_x,_y);
    //设置画布为黑色
    pixmap->fill(Qt::black);
    //在pixmap(画布)上绘图, 附带重置属性
    if(painter.begin(pixmap) == false){qDebug()<<"error";}
    //申明并初始化画笔
    QPen pen1(Qt::red,1,Qt::DashLine,Qt::FlatCap,Qt::RoundJoin);
    //显示亮度图
    int gray = 0;
    QApplication::setOverrideCursor(Qt::WaitCursor);
    QProgressDialog progress;
    progress.setWindowTitle("Rendering");
    progress.setLabelText(QStringLiteral("Rendering images, please wait"));
    progress.setCancelButtonText("CANCEL");
    progress.setRange(0,_vectorLength_intensity );
    progress.setModal(true);

    for(int i=0; i< _vectorLength_intensity; i++){
        progress.setValue(i);
        if(progress.wasCanceled()){
            QMessageBox::warning(NULL,QStringLiteral("TIPS"),QStringLiteral("We only rendered some images for you"));
            return;
        }
        for(int j=0; j < _vectorWidth_intensity; j++){
            gray = _pointsVector_intensity[i][j].intensity;
            if(gray == 0){
                continue;
            }
            //qDebug()<<gray;
//            pen1.setColor(QColor(gray, gray, gray));
//            painter.setPen(pen1);
//            painter.drawPoint(pfVec[i][j]);
            qApp->processEvents(QEventLoop::ExcludeUserInputEvents);
        }
    }
    QApplication::restoreOverrideCursor();

//    for(int i = 0 ; i < (_vectorLength_uniform); i ++){
//        for(int j = 0; j < _vectorWidth_uniform; j++){
//            //显示高度图所用：根据点高度设置不同颜色。可显示模拟器2420 surface mode 的数据
//            if(_pointsVector_uniform[i][j].z<0 /*&& _pointsVector[i][j].z>-10000*/){
//                pen1.setColor(QColor(0, 0, 0));
//            }
//            if(_pointsVector_uniform[i][j].z>0 && _pointsVector_uniform[i][j].z<0.917){
//                pen1.setColor(QColor(0, 255, 255));
//            }
//            if(_pointsVector_uniform[i][j].z>0.917 && _pointsVector_uniform[i][j].z<1.855){
//                pen1.setColor(QColor(0, 255, 0));
//            }
//            if(_pointsVector_uniform[i][j].z>1.855 && _pointsVector_uniform[i][j].z<2.793){
//                pen1.setColor(QColor(255, 255, 0));
//            }
//            if(_pointsVector_uniform[i][j].z>2.793 && _pointsVector_uniform[i][j].z<3.731){
//                pen1.setColor(QColor(255, 0, 0));
//            }
//            if(_pointsVector_uniform[i][j].z>3.731 && _pointsVector_uniform[i][j].z<4.669){
//                pen1.setColor(QColor(255, 0, 255));
//            }
//            if(_pointsVector_uniform[i][j].z>4.669 && _pointsVector_uniform[i][j].z<5.607){
//                pen1.setColor(QColor(255, 0, 255));
//            }
//            if(_pointsVector_uniform[i][j].z>5.607 /*&& _pointsVector[i][j].z<10000*/){
//                pen1.setColor(QColor(0, 0, 0));
//            }
//            painter.setPen(pen1);
//            painter.drawPoint(pfVec[i][j]);
//        }
//    }
    painter.end();
}

//多线程绘制图像
void Display::drawInThread(QPixmap *pix, int y)
{

    //设置画布为黑色
    pixmap->fill(Qt::black);
    //在pixmap(画布)上绘图, 附带重置属性
    QPainter new_p(pixmap);
    new_p.drawPixmap(0,y,_x,_y,*pix);


}


