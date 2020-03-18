#-------------------------------------------------
#
# Project created by QtCreator 2020-01-13T17:22:59
#
#-------------------------------------------------

QT       += qml

QT       -= gui

TARGET = fromlab11
TEMPLATE = lib

DEFINES += FROMLAB11_LIBRARY

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
        fromlab11.cpp \
    acceleration.cpp \
    displacement.cpp \
    speed.cpp

HEADERS += \
        fromlab11.h \
        fromlab11_global.h \ 
    acceleration.h \
    displacement.h \
    speed.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

SUBDIRS += \
    fromlab11.pro