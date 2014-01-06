#-------------------------------------------------
#
# Project created by QtCreator 2013-12-18T23:45:37
#
#-------------------------------------------------

QT       += core gui network\
            testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NameSwitcher
TEMPLATE = app

INCLUDEPATH += /usr/include \
               ForumHandler/Include

#LIBS += -L/usr/lib \
#        -lcurl

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    nameswitcher.cpp \
    textprovider.cpp \
    introscreen.cpp \
    ForumHandler/Source/htmlprovider.cpp \
    ForumHandler/Source/logindataprovider.cpp

HEADERS  += \
    ForumHandler/Include/htmlprovider.h \
    introscreen.h \
    mainwindow.h \
    nameswitcher.h \
    textprovider.h \
    ForumHandler/Include/logindataprovider.h \
    ForumHandler/Include/ihtmlprovider.h

FORMS    += mainwindow.ui \
    introscreen.ui

CONFIG += mobility
MOBILITY = 

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    android/AndroidManifest.xml \
    graphic/krakow_kings_logo.jpg

RESOURCES += \
    resources.qrc

