#-------------------------------------------------
#
# Project created by QtCreator 2021-05-08T22:21:36
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gluttonous_Snake
TEMPLATE = app
RC_ICONS = 000.ico

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    snake.cpp \
    food.cpp \
    denglu.cpp \
    menu.cpp \
    zhuce.cpp \
    user.cpp \
    endgame.cpp \
    setting.cpp \
    userlist.cpp \
    usernode.cpp \
    change_password.cpp \
    ranking.cpp \
    bangzhu.cpp \
    setgame.cpp

HEADERS += \
        mainwindow.h \
    snake.h \
    food.h \
    denglu.h \
    menu.h \
    zhuce.h \
    user.h \
    endgame.h \
    setting.h \
    userlist.h \
    usernode.h \
    change_password.h \
    ranking.h \
    bangzhu.h \
    setgame.h

FORMS += \
        mainwindow.ui \
    denglu.ui \
    menu.ui \
    zhuce.ui \
    endgame.ui \
    setting.ui \
    change_password.ui \
    ranking.ui \
    bangzhu.ui \
    setgame.ui

RESOURCES += \
    res.qrc
