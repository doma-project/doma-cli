cmake_minimum_required(VERSION 3.0)
project(doma-cli)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
set(SOURCES
        ./src/main.cpp
        ./src/app.cpp
        ./src/cli/screen/ScreenBase.cpp
        ./src/cli/screen/Screen0.cpp
        ./src/cli/screen/Screen1_1.cpp
        ./src/cli/screen/EmptyScreen.cpp
        ./src/model/Tag.cpp
        ./src/model/Note.cpp
        ./src/model/Notebook.cpp
        )

add_executable(${PROJECT_NAME} ${SOURCES})
