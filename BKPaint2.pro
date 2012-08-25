#-------------------------------------------------
#
# Project created by QtCreator 2012-08-25T08:09:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BKPaint2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    canvas.cpp \
    paintoperation.cpp \
    addline.cpp \
    addrect.cpp \
    addimage.cpp \
    changeline.cpp \
    changerect.cpp \
    player.cpp \
    mousepress.cpp

HEADERS  += mainwindow.h \
    canvas.h \
    paintoperation.h \
    addline.h \
    addrect.h \
    addimage.h \
    changeline.h \
    changerect.h \
    player.h \
    mousepress.h

FORMS    += mainwindow.ui \
    canvas.ui
