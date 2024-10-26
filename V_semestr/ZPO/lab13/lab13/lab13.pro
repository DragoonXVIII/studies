include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

# GOOGLETEST_DIR = "D:\_workspace\libraries\Addon_CPP_Libraries\googletest-1.15.2"

SOURCES += \
        bankAccountTests.cpp \
        bankaccount.cpp \
        functions.cpp \
        functionsTest.cpp \
        main.cpp \
        number.cpp \
        numberTests.cpp \
        tst_zelo.cpp

HEADERS += \
    bankaccount.h \
    functions.h \
    number.h
