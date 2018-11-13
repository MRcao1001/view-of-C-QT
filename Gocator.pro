#-------------------------------------------------
#
# Project created by QtCreator 2018-11-06T10:20:10
#
#-------------------------------------------------

QT       += core gui opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gocator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        Interface.cpp \
    Sensor.cpp \
    Profilepoint.cpp \
    Display.cpp \
    My_dailog.cpp \
    glwidget.cpp \
    glwindow.cpp

HEADERS += \
        Interface.h \
    Sensor.h \
    Profilepoint.h \
    Display.h \
    My_dailog.h \
    glwidget.h \
    glwindow.h

#调用静态库 KApi
win32: LIBS += -L$$PWD/./ -lkApi

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/./kApi.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/./libkApi.a


#调用静态库 GoSdk
win32: LIBS += -L$$PWD/./ -lGoSdk

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/./GoSdk.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/./libGoSdk.a


#调用oepngl类库
LIBS += -lglut32
LIBS += -LC:\glut

RESOURCES += \
    img.qrc

FORMS += \
    glwindow.ui

#添加halcon的类库
win32: LIBS += -L$$PWD/'../../../Program Files/MVTec/HALCON-17.12-Progress/lib/x64-win64/' -lhalcon
win32: LIBS += -L$$PWD/'../../../Program Files/MVTec/HALCON-17.12-Progress/lib/x64-win64/' -lhalconc
win32: LIBS += -L$$PWD/'../../../Program Files/MVTec/HALCON-17.12-Progress/lib/x64-win64/' -lhalconcpp
win32: LIBS += -L$$PWD/'../../../Program Files/MVTec/HALCON-17.12-Progress/lib/x64-win64/' -lhalconcppxl
win32: LIBS += -L$$PWD/'../../../Program Files/MVTec/HALCON-17.12-Progress/lib/x64-win64/' -lhalconcxl
win32: LIBS += -L$$PWD/'../../../Program Files/MVTec/HALCON-17.12-Progress/lib/x64-win64/' -lhalconxl
win32: LIBS += -L$$PWD/'../../../Program Files/MVTec/HALCON-17.12-Progress/lib/x64-win64/' -lhdevenginecpp
win32: LIBS += -L$$PWD/'../../../Program Files/MVTec/HALCON-17.12-Progress/lib/x64-win64/' -lhdevenginecppxl

INCLUDEPATH += $$PWD/'../../../Program Files\MVTec\HALCON-17.12-Progress\include'
DEPENDPATH += $$PWD/'../../../Program Files/MVTec/HALCON-17.12-Progress/lib/x64-win64'
