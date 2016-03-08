#-------------------------------------------------
#
# Project created by QtCreator 2016-03-02T20:43:17
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AlarmClock
TEMPLATE = app


SOURCES += main.cpp \
    MainWindow.cpp \
    QuitPromptWindow.cpp \
    MyTableView.cpp \
    AddAlarmClockWidget.cpp \
    GlobalFunctions.cpp \
    TimerManage.cpp \
    MyTimer.cpp \
    MusicPlayer.cpp

HEADERS  += \
    MainWindow.h \
    common.h \
    QuitPromptWindow.h \
    MyTableView.h \
    AddAlarmClockWidget.h \
    GlobalFunctions.h \
    TimerManage.h \
    MyTimer.h \
    MusicPlayer.h

RESOURCES += \
    resources.qrc
