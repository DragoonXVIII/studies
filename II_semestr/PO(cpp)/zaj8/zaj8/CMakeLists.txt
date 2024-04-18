cmake_minimum_required(VERSION 3.5)

project(zaj8 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(zaj8 main.cpp
                    tdomownik.h tdomownik.cpp
                    tsasiad.h tsasiad.cpp
                    tpunkt.h tpunkt.cpp
                    tkolo.h tkolo.cpp)

install(TARGETS zaj8
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
