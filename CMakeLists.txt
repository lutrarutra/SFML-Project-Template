cmake_minimum_required(VERSION 3.1)

# Get project name from folder name
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

# Use c++ 14
set(CMAKE_CXX_STANDARD 17)

# All .cpp-files
set(SOURCES src/main.cpp)

# Enable additional warnings and debug mode
set (CMAKE_CXX_FLAGS "-g -W -pedantic")

include_directories(src)

# 3rd party dependencies
add_subdirectory(lib)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE ImGui-SFML::ImGui-SFML)

# Additional resources like images and fonts
# configure_file(res/OpenSans-Regular.ttf OpenSans-Regular.ttf COPYONLY)

# Set "a" as output's name
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "a")