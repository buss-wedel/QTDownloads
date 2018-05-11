#-------------------------------------------------
#
# Project created by QtCreator 2018-03-06T17:47:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtDownloads
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

VERSION = 0.0.1

DEFINES += APPLICATION_VERSION=\\\"$${VERSION}\\\"
DEFINES += APPLICATION_NAME=\\\"QtDownloads\\\"
DEFINES += ORGANIZATION_NAME=\\\"Buss-Wedel\\\"
DEFINES += ORGANIZATION_DOMAIN=\\\"https://github.com/buss-wedel/QTDownloads/\\\"

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    aboutdialog.cpp \
    downloadlistsettingsdialog.cpp \
    downloadlistcategorydialog.cpp \
    downloadlistitemdialog.cpp

HEADERS += \
        mainwindow.h \
    aboutdialog.h \
    downloadlistsettingsdialog.h \
    downloadlistcategorydialog.h \
    downloadlistitemdialog.h

RESOURCES += \
    qtdl_ressources.qrc

win32:RC_ICONS += icons/favicon.ico

include(../core/core.pri)
include(../3rdparty/3rdparty.pri)
