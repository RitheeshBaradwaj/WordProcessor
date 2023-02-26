cmake_minimum_required(VERSION 3.5)

project(WordProcessorTool)

set(NAME "WordProcessor")

# Set C++ version to 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set the below values correctly if required
# set(GTEST_LOCAL_PATH "/home/user/googletest")
# set(GTEST_ROOT "${GTEST_LOCAL_PATH}/googletest")
# set(GTEST_LIBRARY "${GTEST_LOCAL_PATH}/build/lib/libgtest.a")
# set(GTEST_MAIN_LIBRARY "${GTEST_LOCAL_PATH}/build/lib/libgtest_main.a")
# set(GTEST_INCLUDE_DIRS "${GTEST_ROOT}/include")
# set(GMOCK_INCLUDE_DIRS "${GTEST_LOCAL_PATH}/googlemock/include")

set(BINARY_DIR ${CMAKE_SOURCE_DIR}/_bin/bin)

# Source files
file(GLOB SOURCES "src/wordtool/*.cpp")

# Build executable
add_executable(${NAME} ${SOURCES})

# Include directories
target_include_directories(${NAME}
    PRIVATE
        include/
)

# Set compiler flags
target_compile_options(${NAME} PRIVATE -Wall -pedantic)
target_link_libraries(${NAME} pthread)

# Install binary to _bin directory
set_target_properties(${NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIR})
install(TARGETS ${TEST_NAME} DESTINATION ${BINARY_DIR})

# testing
# Enable testing
enable_testing()
add_subdirectory(tests)
