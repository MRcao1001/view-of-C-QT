#include "My_dailog.h"
//接收数据过程中的弹窗

my_Dailog::my_Dailog(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(400,638);
    vbox = new QVBoxLayout;
    label = new QLabel;
    label->setFixedSize(400, 138);
    label_2 = new QLabel;
    label_2->setFixedSize(400, 138);
    tips = new QLabel;
    tips->setAlignment(Qt::AlignTop);
    tips->setFixedSize(400,500);
    tips->setFont(QFont("generally", 10));
    tips->setStyleSheet("background-color:#fff; padding:10px;");
    vbox->addWidget(label);
    vbox->addWidget(label_2);
    vbox->addWidget(tips);
    vbox->setMargin(0);
    vbox->setSpacing(0);
    movie = new QMovie(":/img/loading.gif");
    movie_2 = new QMovie(":/img/ok.gif");
    movie->setScaledSize(QSize(400,138));
    movie_2->setScaledSize(QSize(400,138));
    label->setScaledContents(true);
    label->setMovie(movie);
    label_2->setScaledContents(true);
    label_2->setMovie(movie_2);
    movie->start();

    label_2->hide();
    this->setLayout(vbox);

    timer = new QTimer;
    anmation = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(get_onData()));
    connect(anmation, SIGNAL(timeout()), this, SLOT(close()));
    timer->start(500);
    qDebug()<<"loading";
}

//判断数据是否接收完毕
void my_Dailog::get_onData()
{
    tips->setText(print_string);
    if(onData_ok){
        //        emit onData_ok_is_true();
        movie_2->start();
        label->hide();
        label_2->show();
        print_string+="加载完成!";
        timer->stop();
        anmation->start(1200);
        emit onData_ok_is_true();
    }
    if(Erroneous){
        int rec = QMessageBox::critical(NULL,
                             QStringLiteral("ERROR"),
                             QStringLiteral("The initialization sensor is an unexpected error.Check if the sensor is online,and then try again"),
                             QMessageBox::Yes);

        if(QMessageBox::Yes == rec){
            Erroneous = false;
            timer->stop();
            this->close();
            this->deleteLater();
        }
    }
}
