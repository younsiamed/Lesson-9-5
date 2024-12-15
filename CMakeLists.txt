cmake_minimum_required(VERSION 3.21)

# Имя проекта
project(StopwatchApp LANGUAGES CXX)

# Установить стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Найти Qt6 модули
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Указать исходные файлы
set(SOURCES
    main.cpp
    mainwindow.cpp
    stopwatch.cpp
)

set(HEADERS
    mainwindow.h
    stopwatch.h
)

set(UI
    mainwindow.ui
)

# Создание исполняемого файла
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${UI})

# Подключить Qt6 библиотеки
target_link_libraries(${PROJECT_NAME} Qt6::Widgets)

# Указать путь для сборки MOC, UI и других временных файлов
set_target_properties(${PROJECT_NAME} PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON)

# Указать включаемые директории
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
