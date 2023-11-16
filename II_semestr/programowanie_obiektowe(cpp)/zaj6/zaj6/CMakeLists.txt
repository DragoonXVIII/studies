cmake_minimum_required(VERSION 3.5)

project(zaj6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(zaj6 main.cpp
    instrument.cpp instrument.h
    trumpet.cpp trumpet.h
    violin.cpp violin.h

    figura.cpp figura.h
    kolo.cpp kolo.h
    prostokat.cpp prostokat.h
    kwadrat.cpp kwadrat.h
    afigura.h afigura.cpp
    kolo2.h kolo2.cpp
    prostokat2.h prostokat2.cpp
    kwadrat2.h kwadrat2.cpp
)

install(TARGETS zaj6
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
