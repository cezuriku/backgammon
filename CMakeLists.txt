cmake_minimum_required(VERSION 3.4)

project(backgammon)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_NAME ${PROJECT_NAME})
set(TEST_NAME "${EXECUTABLE_NAME}Test")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -W -Wall -Wextra -g")

# Configuration
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

# Executable
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

################################################################################
# Test Section
################################################################################

enable_testing()

# Get all test files
file(GLOB_RECURSE TEST_FILES "test/*.cpp")
add_executable(${TEST_NAME} ${TEST_FILES})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

find_package(Threads)
target_link_libraries(${TEST_NAME}
                      ${GTEST_BOTH_LIBRARIES}
                      ${CMAKE_THREAD_LIBS_INIT})

add_test(AllTests "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TEST_NAME}")
