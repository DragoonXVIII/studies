TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        doublylinkedlist.cpp \
        main.cpp \
        node.cpp \
        shop.cpp \
        warehouse.cpp

HEADERS += \
    doublylinkedlist.h \
    node.h \
    shop.h \
    warehouse.h
