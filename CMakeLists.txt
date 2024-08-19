cmake_minimum_required(VERSION 3.5)
project(InkwellBeta)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ensure that the AUTOMOC, AUTOUIC, and AUTORCC are on for Qt projects
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Set the CMake prefix path to include the correct Qt installation directory
set(CMAKE_PREFIX_PATH "/Users/AfamObioha/Qt/6.6.3/macos/lib/cmake" CACHE STRING "Qt6 CMake prefix path")

# Optionally, you can include the environment variable method for flexibility
if(DEFINED ENV{MY_CMAKE_PATH})
    list(APPEND CMAKE_PREFIX_PATH $ENV{MY_CMAKE_PATH})
endif()

# Find the necessary Qt modules
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Set translation source files if any
set(TS_FILES kaminari_prime_en_US.ts)

# Define the project sources
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    FolderWidget.cpp
    FolderWidget.h
    NewItemDialog.cpp
    NewItemDialog.h
    NewFolderDialog.cpp
    NewFolderDialog.h
    SketchPage.cpp
    SketchPage.h
    ${TS_FILES}
)

# Process the .qrc resource file
qt6_add_resources(PROJECT_SOURCES myresources.qrc)

# Create the executable with the project sources
add_executable(InkwellBeta ${PROJECT_SOURCES})

# Link the executable to the necessary Qt modules
target_link_libraries(InkwellBeta PRIVATE Qt6::Widgets)