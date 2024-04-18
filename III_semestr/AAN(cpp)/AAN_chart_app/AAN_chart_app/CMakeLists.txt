cmake_minimum_required(VERSION 3.16)

project(AAN_chart_app VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Charts)

qt_standard_project_setup()

qt_add_executable(appAAN_chart_app
    main.cpp
)

qt_add_qml_module(appAAN_chart_app
    URI AAN_chart_app
    VERSION 1.0
    QML_FILES Main.qml
    SOURCES lsm.cpp lsm.h
    RESOURCES copyPaste

)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appAAN_chart_app PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appAAN_chart_app
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appAAN_chart_app PRIVATE Qt6::Charts)
target_link_libraries(appAAN_chart_app PRIVATE Qt6::Quick)

include(GNUInstallDirs)
install(TARGETS appAAN_chart_app
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
