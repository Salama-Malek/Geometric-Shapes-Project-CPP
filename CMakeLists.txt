cmake_minimum_required (VERSION 3.26)

project (oop1_ex01)
set (MY_AUTHORS "")

include (cmake/CompilerSettings.cmake)

# Add all source files
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Add the executable and link source files
add_executable (${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

# Include directories if needed
# target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE include)

# Comment or remove the next lines to disable AddressSanitizer
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)

add_subdirectory (include)
add_subdirectory (src)

include (cmake/Zip.cmake)
