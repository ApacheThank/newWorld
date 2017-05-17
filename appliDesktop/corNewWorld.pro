#-------------------------------------------------
#
# Project created by QtCreator 2017-03-03T13:46:55
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = corNewWorld
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialogconnect.cpp \
    mainwindow2.cpp \
    dialogaddproduct.cpp

HEADERS  += mainwindow.h \
    dialogconnect.h \
    mainwindow2.h \
    dialogaddproduct.h

FORMS    += mainwindow.ui \
    dialogconnect.ui \
    mainwindow2.ui \
    dialogaddproduct.ui
