cmake_minimum_required(VERSION 3.1)

project(sample-qt)

set (CMAKE_CXX_STANDARD 14)

include(cmake/qt5.cmake)

file(GLOB FRAMEWORK_CODES fwk/*.cpp)
include_directories(fwk)

file(GLOB MAIN_CODES src/*.cpp)
include_directories(src)

# Tell CMake to create the helloworld executable
add_executable(sample-qt main.cpp ${MAIN_CODES} ${FRAMEWORK_CODES})

# Use the Widgets module from Qt 5.
#target_link_libraries(sample-qt appcode)
target_link_libraries(sample-qt Qt5::Widgets)

if(NOT without-test)
  enable_testing()
  include(cmake/gtest.cmake)
  add_subdirectory(test)
endif()
