cmake_minimum_required(VERSION 3.5)
project(SimpleQtApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ensure that the AUTOMOC, AUTOUIC, and AUTORCC are on for Qt projects
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

list(APPEND CMAKE_PREFIX_PATH "/Users/AfamObioha/Qt/6.6.2/macos/lib/cmake")


find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(TS_FILES kaminari_prime_en_US.ts)  # Include translation source files if any

set(PROJECT_RESOURCES
        myresources.qrc
)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${TS_FILES}
)


add_executable(SimpleQtApp main.cpp mainwindow.cpp mainwindow.ui FolderWidget.cpp ${RESOURCES})

# Use this command to process resource files
qt6_add_resources(SimpleQtApp "resources" SOURCE_DIR "/Users/AfamObioha/kaminari_prime" FILES ${PROJECT_RESOURCES})

target_link_libraries(SimpleQtApp PRIVATE Qt6::Widgets)
# If you have additional library dependencies, link them here as well
# target_link_libraries(kaminari_prime PRIVATE SomeOtherLibrary)

# If you have any install commands, include them here
# install(TARGETS kaminari_prime RUNTIME DESTINATION bin)

# If you have any additional custom commands or targets, include them here
