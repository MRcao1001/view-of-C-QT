#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
    qDebug()<<"enter glfunction";
    draw();
}

void GLWidget::initializeGL()
{
    glClearColor(0, 0.2, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw();
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat x = GLfloat(w) / h;
    glFrustum(-x, x, -1.0, 1.0, 4.0, 15.0);
    glMatrixMode(GL_MODELVIEW);
}

void GLWidget::draw()
{
//    //显示亮度图
//    int gray = 0;
//    QApplication::setOverrideCursor(Qt::WaitCursor);
//    QProgressDialog progress;
//    progress.setWindowTitle("Rendering");
//    progress.setLabelText(QStringLiteral("Rendering images, please wait"));
//    progress.setCancelButtonText("CANCEL");
//    progress.setRange(0,_vectorLength_intensity );
//    progress.setModal(true);

//    qDebug()<<_vectorLength_intensity;
//    for(int i=0; i< _vectorLength_intensity; i++){
//        progress.setValue(i);
//        if(progress.wasCanceled()){
//            QMessageBox::warning(NULL,QStringLiteral("TIPS"),QStringLiteral("We only rendered some images for you"));
//            return;
//        }
//        for(int j=0; j < _vectorWidth_intensity; j++){
//            gray = _pointsVector_intensity[i][j].intensity;
//            if(gray == 0){
//                continue;
//            }
//            //qDebug()<<gray;
//            glColor3i(gray, gray, gray);
//            glBegin(GL_POINTS);
//            glVertex2f(pfVec[i][j].x(), pfVec[i][j].y());
//            glEnd();
//            qApp->processEvents(QEventLoop::ExcludeUserInputEvents);
//        }
//        update();
//    }
//    QApplication::restoreOverrideCursor();
//    glFlush();
//    qDebug()<<"finished drawing";


}
