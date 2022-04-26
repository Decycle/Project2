QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    canvasmanager.cpp \
    graph.cpp \
    line.cpp \
    loginpage.cpp \
    main.cpp \
    mainwindow.cpp \
    stadium.cpp \
    stadiumeditpage.cpp \
    stadiummaster.cpp \
    tableviewpage.cpp

HEADERS += \
    canvasmanager.h \
    graph.h \
    line.h \
    lineitem.h \
    loginpage.h \
    mainwindow.h \
    stadium.h \
    stadiumeditpage.h \
    stadiummaster.h \
    tableviewpage.h \
    vertexItem.h

FORMS += \
    loginpage.ui \
    mainwindow.ui \
    stadiumeditpage.ui \
    tableviewpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    global.qrc
