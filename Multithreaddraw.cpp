#include "Multithreaddraw.h"

MultiThreadDraw::MultiThreadDraw(int _temp)
{
    start_export = 0;
    temp = _temp;
}

void MultiThreadDraw::run()
{
    start_draw();
}

void MultiThreadDraw::start_draw()
{
    pix = new QPixmap(_x,_y);
    //设置画布为黑色
    pix->fill(Qt::black);
    //在pixmap(画布)上绘图, 附带重置属性
    if(painter.begin(pix) == false){qDebug()<<"error";}
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

    for(int i=temp; i< _vectorLength_intensity/5; i++){
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
            pen1.setColor(QColor(gray, gray, gray));
            painter.setPen(pen1);
            painter.drawPoint(public_pVec[i][j]);
            qApp->processEvents(QEventLoop::ExcludeUserInputEvents);
        }
    }
    emit send_pixmap(pix, temp);
    QApplication::restoreOverrideCursor();

}

