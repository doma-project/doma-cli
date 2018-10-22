cmake_minimum_required(VERSION 3.0)
project(doma-cli)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
set(SOURCES
        ./src/main.cpp
        ./src/app.cpp
        ./src/screen/ScreenBase.cpp
        ./src/screen/Screen0.cpp
        ./src/screen/Screen1_1.cpp
        ./src/screen/EmptyScreen.cpp
        )

add_executable(${PROJECT_NAME} ${SOURCES})
