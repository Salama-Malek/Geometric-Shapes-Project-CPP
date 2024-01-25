file (GLOB_RECURSE MY_SOURCE_FILES CONFIGURE_DEPENDS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
target_sources (${CMAKE_PROJECT_NAME} PRIVATE ${MY_SOURCE_FILES} "../include/Rectangle.h" "../include/Triangle.h" "../include/Window.h" "../include/Hexagram.h" "Rectangle.cpp" "Triangle.cpp" "Window.cpp" "Hexagram.cpp")
