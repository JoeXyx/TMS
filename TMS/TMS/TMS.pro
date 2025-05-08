QT       += core gui
QT+=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addtaskform.cpp \
    bst.cpp \
    chgtaskform.cpp \
    circularprogressbar.cpp \
    data_sql.cpp \
    dlttaskform.cpp \
    focusdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    reminderdialog.cpp \
    srcchgform.cpp \
    srctaskform.cpp \
    tdlist.cpp \
    todo.cpp

HEADERS += \
    addtaskform.h \
    bst.h \
    chgtaskform.h \
    circularprogressbar.h \
    data_sql.h \
    dlttaskform.h \
    focusdialog.h \
    mainwindow.h \
    reminderdialog.h \
    srcchgform.h \
    srctaskform.h \
    tdlist.h \
    todo.h

FORMS += \
    addtaskform.ui \
    chgtaskform.ui \
    dlttaskform.ui \
    focusdialog.ui \
    mainwindow.ui \
    reminderdialog.ui \
    srcchgform.ui \
    srctaskform.ui \
    tdlist.ui \
    todo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc
