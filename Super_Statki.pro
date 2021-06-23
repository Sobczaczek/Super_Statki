INCLUDEPATH += "D:/Programy/QT/SFML-2.5.1/include"
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

LIBS += -L"D:/Programy/QT/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    cscreen.h \
    screen_0.h \
    screen_1.h \
    screen_2.h \
    screen_3.h \
    screen_4.h \
    screen_5.h \
    screens.h
