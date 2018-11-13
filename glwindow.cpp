#include "glwindow.h"
#include "ui_glwindow.h"

glWindow::glWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::glWindow)
{
    qDebug()<<"create glwindow";
    ui->setupUi(this);
    ui->widget->resize(600,600);
    this->setFixedSize(600,600);
}

glWindow::~glWindow()
{
    delete ui;
}
