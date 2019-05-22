#-------------------------------------------------
#
# Project created by QtCreator 2017-06-28T14:59:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Choose
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    management.cpp \
    module.cpp \
    score.cpp \
    staff.cpp \
    student.cpp \
    managerwindow.cpp \
    stumanagement.cpp \
    studialog.cpp \
    stadialog.cpp \
    stamanagement.cpp

HEADERS  += mainwindow.h \
    management.h \
    module.h \
    Myvector.h \
    score.h \
    staff.h \
    student.h \
    stamanagement.h \
    stumanagement.h \
    studialog.h \
    stadialog.h

FORMS    += mainwindow.ui \
    studialog.ui \
    stadialog.ui
