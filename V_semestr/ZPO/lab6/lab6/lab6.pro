TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        contact.cpp \
        contacts.cpp \
        main.cpp \
        person.cpp

# Ustaw ścieżkę do Boost
BOOST_ROOT = D:/_workspace/libraries/Addon_CPP_Libraries/boost_1_86_0  # Upewnij się, że to jest poprawna ścieżka

INCLUDEPATH += $$BOOST_ROOT
LIBS += -L$$BOOST_ROOT/stage/lib # Dodaj inne potrzebne biblioteki

HEADERS += \
    contact.h \
    contacts.h \
    person.h