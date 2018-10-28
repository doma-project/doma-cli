cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(doma-cli VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED 14)

add_compile_options(
        "-Wall"
        "-Wextra"
        "-Wunused"
        "-Wpedantic"
        "-Weffc++"
        "-Werror"
)

include_directories(include)
set(SOURCES
        ./src/main.cpp
        ./src/app.cpp
        ./src/cli/screen/ScreenBase.cpp
        ./src/cli/screen/Screen0.cpp
        ./src/cli/screen/Screen1_1.cpp
        ./src/cli/screen/Screen1_2.cpp
        ./src/cli/screen/EmptyScreen.cpp
        ./src/model/Tag.cpp
        ./src/model/Note.cpp
        ./src/model/Notebook.cpp
        )

add_executable(${PROJECT_NAME} ${SOURCES})
