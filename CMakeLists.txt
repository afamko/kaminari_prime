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

# list(APPEND CMAKE_PREFIX_PATH "/Users/AfamObioha/Qt/6.6.2/macos/lib/cmake")

if(DEFINED ENV{MY_CMAKE_PATH})
    list(APPEND CMAKE_PREFIX_PATH $ENV{MY_CMAKE_PATH})
endif()


find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(TS_FILES kaminari_prime_en_US.ts)  # Include translation source files if any



set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    FolderWidget.cpp
    FolderWidget.h  # Add this line if you have a header file for FolderWidget
    NewItemDialog.cpp  # Add your NewItemDialog source file
    NewItemDialog.h    # Add your NewItemDialog header file
    ${TS_FILES}
)

# Process the .qrc resource file
 qt6_add_resources(PROJECT_SOURCES myresources.qrc)


# Create the executable with the project sources
add_executable(InkwellBeta ${PROJECT_SOURCES})

# Link the executable to the necessary Qt modules
target_link_libraries(InkwellBeta PRIVATE Qt6::Widgets)
