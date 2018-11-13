#ifndef MY_DAILOG_H
#define MY_DAILOG_H

#include <QWidget>
#include <QLabel>
#include <QFrame>
#include <QTimer>
#include <QMovie>
#include <QMessageBox>
#include "Sensor.h"
#include <QVBoxLayout>
class my_Dailog : public QWidget
{
    Q_OBJECT
public:
    my_Dailog(QWidget *parent = nullptr);
    QMovie *movie;
    QMovie *movie_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *tips;
    QLabel * tip_label;
    QFrame * background;
    QVBoxLayout *vbox;
    QTimer *timer ;
    QTimer *anmation;
signals:
    void onData_ok_is_true();
public slots:
    void get_onData();
};

#endif // MY_DAILOG_H
