QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adddish.cpp \
    addrecipes.cpp \
    addseller.cpp \
    adminwindow.cpp \
    changeordingr.cpp \
    deletedish.cpp \
    deleterec.cpp \
    deleteseller.cpp \
    dialog.cpp \
    main.cpp \
    nazenka.cpp \
    order.cpp \
    pricesmin.cpp \
    profit.cpp \
    sellersalary.cpp \
    sellerwindow.cpp \
    storage.cpp \
    storingradd.cpp \
    storingrdelete.cpp \
    supplierwindow.cpp

HEADERS += \
    adddish.h \
    addrecipes.h \
    addseller.h \
    adminwindow.h \
    changeordingr.h \
    deletedish.h \
    deleterec.h \
    deleteseller.h \
    dialog.h \
    nazenka.h \
    order.h \
    pricesmin.h \
    profit.h \
    sellersalary.h \
    sellerwindow.h \
    storage.h \
    storingradd.h \
    storingrdelete.h \
    supplierwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    adddish.ui \
    addrecipes.ui \
    adminwindow.ui \
    deletedish.ui \
    dialog.ui \
    nazenka.ui \
    order.ui \
    pricesmin.ui \
    profit.ui \
    sellersalary.ui \
    sellerwindow.ui \
    storage.ui \
    supplierwindow.ui
