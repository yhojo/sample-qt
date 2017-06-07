cmake_minimum_required(VERSION 3.1)

include(../cmake/qt5.cmake)

ExternalProject_Get_Property(GoogleTest source_dir)
include_directories(${source_dir}/googlemock/include)

file(GLOB FRAMEWORK_CODES ../fwk/*.cpp)
include_directories(../fwk)

file(GLOB MAIN_CODES ../src/*.cpp)
include_directories(../src)

file(GLOB TEST_SOURCE_FILES *.cpp)

add_executable(run_test ${TEST_SOURCE_FILES} ${FRAMEWORK_CODES} ${MAIN_CODES})

target_link_libraries(run_test Qt5::Widgets)
target_link_libraries(run_test gmock gmock_main pthread)

add_test(
  NAME run_test
  COMMAND $<TARGET_FILE:run_test>
)
