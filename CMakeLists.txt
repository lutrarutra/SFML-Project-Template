cmake_minimum_required(VERSION 2.8)
project(sfml_cmake_skeleton)

set(CMAKE_CXX_STANDARD 14)


set(SOURCES src/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "a")

set (CMAKE_CXX_FLAGS "-g -W -pedantic")

include_directories(src)

# Additional resources like images and fonts
configure_file(res/OpenSans-Regular.ttf OpenSans-Regular.ttf COPYONLY)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(SFML/include)
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
