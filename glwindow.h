#ifndef GLWINDOW_H
#define GLWINDOW_H

#include <QWidget>

namespace Ui {
class glWindow;
}

class glWindow : public QWidget
{
    Q_OBJECT

public:
    explicit glWindow(QWidget *parent = 0);
    ~glWindow();

private:
    Ui::glWindow *ui;
};

#endif // GLWINDOW_H
