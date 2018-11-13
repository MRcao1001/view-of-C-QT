#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QObject>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QWidget>
#include <QApplication>
#include <QProgressDialog>
#include <QMessageBox>
#include <glut>
#include "Sensor.h"


class GLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    GLWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void draw();

};

#endif // QGLWIDGET_H
