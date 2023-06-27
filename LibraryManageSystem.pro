QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acterror.cpp \
    adminpage.cpp \
    bookeditpage.cpp \
    main.cpp \
    firstwindow.cpp \
    newbookpage.cpp \
    pwdcmperror.cpp \
    pwderror.cpp \
    searchpage.cpp \
    signsuccess.cpp \
    signuppage.cpp \
    user.cpp \
    usercenter.cpp \
    userpage.cpp

HEADERS += \
    acterror.h \
    adminpage.h \
    bookeditpage.h \
    errors.h \
    firstwindow.h \
    newbookpage.h \
    pwdcmperror.h \
    pwderror.h \
    searchpage.h \
    signsuccess.h \
    signuppage.h \
    user.h \
    usercenter.h \
    userpage.h

FORMS += \
    acterror.ui \
    adminpage.ui \
    bookeditpage.ui \
    firstwindow.ui \
    newbookpage.ui \
    pwdcmperror.ui \
    pwderror.ui \
    searchpage.ui \
    signsuccess.ui \
    signuppage.ui \
    usercenter.ui \
    userpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
