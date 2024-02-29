cmake_minimum_required(VERSION 3.5)
project(InkwellBeta)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ensure that the AUTOMOC, AUTOUIC, and AUTORCC are on for Qt projects
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

list(APPEND CMAKE_PREFIX_PATH "/Users/AfamObioha/Qt/6.6.2/macos/lib/cmake")

find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(TS_FILES kaminari_prime_en_US.ts)  # Include translation source files if any



set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    FolderWidget.cpp
    ${TS_FILES}
)

# Process the .qrc resource file
 qt6_add_resources(PROJECT_SOURCES myresources.qrc)


# Create the executable with the project sources
add_executable(InkwellBeta ${PROJECT_SOURCES})

# Link the executable to the necessary Qt modules
target_link_libraries(InkwellBeta PRIVATE Qt6::Widgets)
