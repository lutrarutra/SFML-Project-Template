cmake_minimum_required(VERSION 2.8)

# Get project name from folder name
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

# Use c++ 11
set(CMAKE_CXX_STANDARD 11)

# Enable additional warnings
# add_compile_options(-Wall -Wextra -Wpedantic)

# Folder for header files (".h"-files)
include_directories(src)

# Additional resources like images and fonts
configure_file(res/OpenSans-Regular.ttf OpenSans-Regular.ttf COPYONLY)

# All .cpp-files
set(SOURCES src/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

# Find sfml and link it
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

# Set "a" as output's name
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "a")