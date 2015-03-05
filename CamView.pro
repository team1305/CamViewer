#-------------------------------------------------
#
# Project created by QtCreator 2015-03-04T18:08:49
#
#-------------------------------------------------

QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CamView
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

QT += multimedia multimediawidgets widgets

DISTFILES += \
    icon.png \
    Camview.rc

RC_FILE = Camview.rc
