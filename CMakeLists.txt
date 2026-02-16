cmake_minimum_required(VERSION 3.16)

project(demoproject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.h mainwindow.cpp
        surnamewindow.h surnamewindow.cpp
        installerwindow.h installerwindow.cpp
        packages.qrc
)

add_executable(demoproject ${PROJECT_SOURCES})

target_link_libraries(demoproject Qt5::Widgets)
