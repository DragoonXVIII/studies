cmake_minimum_required(VERSION 3.5)

project(metodaNajmniejszychKwadratow LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(metodaNajmniejszychKwadratow main.cpp)

include(GNUInstallDirs)
install(TARGETS metodaNajmniejszychKwadratow
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
