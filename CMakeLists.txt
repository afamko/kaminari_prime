cmake_minimum_required(VERSION 3.5)
project(InkwellBeta)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ensure that the AUTOMOC, AUTOUIC, and AUTORCC are on for Qt projects
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# It's better to set Qt's CMAKE_PREFIX_PATH in the environment variable rather than in the CMake file
# This way, each developer can have their own Qt setup
# For example, you can set it in your .bashrc or .zshrc: export CMAKE_PREFIX_PATH="$HOME/Qt/6.6.2/macos/lib/cmake"

find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(TS_FILES kaminari_prime_en_US.ts)  # Include translation source files if any

# Resource files
set(PROJECT_RESOURCES
    myresources.qrc
)

# Specify all sources and resource files
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    FolderWidget.cpp
    ${TS_FILES}
    ${PROJECT_RESOURCES} # Include the resource file in the project sources
)

# Automatically process resource files
qt6_add_resources(PROJECT_SOURCES ${PROJECT_RESOURCES})

# Create the executable with the project sources
add_executable(InkwellBeta ${PROJECT_SOURCES})

# Link the executable to the necessary Qt modules
target_link_libraries(InkwellBeta PRIVATE Qt6::Widgets)
