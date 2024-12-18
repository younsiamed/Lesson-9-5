cmake_minimum_required(VERSION 3.16)
project(StopwatchApp)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(${PROJECT_NAME}
    main.cpp
    MainWindow.cpp
    MainWindow.h
    Stopwatch.cpp
    Stopwatch.h
    mainwindow.ui
)

target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets)
