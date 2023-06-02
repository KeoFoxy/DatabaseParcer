cmake_minimum_required(VERSION 3.20)
project(DatabaseParcer VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS
#        ${CMAKE_CURRENT_LIST_DIR}/UI
        )


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(PROJECT_SOURCES
        # Utils
        Utils/abstractreader.h
        Utils/abstractreader.cpp

        # CSV Workers
        CSV/csvreader.h
        CSV/csvreader.cpp
        CSV/csvwriter.h
        CSV/csvwriter.cpp

        #JSON Workers
        JSON/json.hpp
        JSON/jsonreader.h
        JSON/jsonreader.cpp

        #Parcing database class
        films.h
        films.cpp

        # Colorful text browser
        UI/customtextbrowser.h
        UI/customtextbrowser.cpp

        #Mainwindow

        mainwindow.h
        mainwindow.cpp
        mainwindow.ui

        main.cpp)

add_executable(DatabaseParcer
        ${PROJECT_SOURCES}
        main.cpp)


target_link_libraries(DatabaseParcer
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

target_include_directories(DatabaseParcer PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/CSV
        ${CMAKE_CURRENT_LIST_DIR}/JSON
        ${CMAKE_CURRENT_LIST_DIR}/UI
        ${CMAKE_CURRENT_LIST_DIR}/Utils
        ${CMAKE_CURRENT_LIST_DIR}/Databases
        )