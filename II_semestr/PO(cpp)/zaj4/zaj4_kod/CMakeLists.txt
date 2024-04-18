cmake_minimum_required(VERSION 3.5)

project(zaj4_kod LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(zaj4_kod main.cpp data.cpp data.h o_osoba.cpp o_osoba.h tosobas.cpp tosobas.h)

install(TARGETS zaj4_kod
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
