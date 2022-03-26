QT       += core gui
#QT +=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    loginpage.cpp \
    main.cpp \
    mainwindow.cpp \
    sqlite/sqlite3.c

HEADERS += \
    loginpage.h \
    mainwindow.h \
    sqlite/include/sqlite3.h \
    sqlite/include/sqlite3ext.h



FORMS += \
    loginpage.ui \
    mainwindow.ui
INCLUDEPATH +=sqlite/include
LIBS += -L "sqlite/lib/" -I libsqlite3


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    sqlite/lib/libsqlite3.a
