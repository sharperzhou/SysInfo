QT += core gui charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++14

TEMPLATE = app
TARGET = SysInfo

HEADERS += \
    sysinfo.h \
    sysinfowindowsimpl.h \
    sysinfowidget.h \
    cpuwidget.h \
    mainwindow.h \
    memorywidget.h

SOURCES += \
    sysinfowindowsimpl.cpp \
    sysinfo.cpp \
    sysinfowidget.cpp \
    cpuwidget.cpp \
    mainwindow.cpp \
    main.cpp \
    memorywidget.cpp

FORMS += \
    mainwindow.ui
