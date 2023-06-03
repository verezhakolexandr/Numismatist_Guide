QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcoin.cpp \
    addcollector.cpp \
    coin.cpp \
    coincollector.cpp \
    coincollectorstable.cpp \
    coinstable.cpp \
    dbmanager.cpp \
    main.cpp \
    mainwindow.cpp \
    sqlitedbmanager.cpp

HEADERS += \
    addcoin.h \
    addcollector.h \
    coin.h \
    coincollector.h \
    coincollectorstable.h \
    coinstable.h \
    dbmanager.h \
    mainwindow.h \
    sqlitedbmanager.h

FORMS += \
    addcoin.ui \
    addcollector.ui \
    coincollectorstable.ui \
    coinstable.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
