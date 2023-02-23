# List of source files for the unit test
set(TEST_NAME Word_UT)
set(TEST_SOURCES
    ${TEST_NAME}.cpp
    ${CMAKE_SOURCE_DIR}/src/wordtool/word.cpp
)

# Add the unit test executable
add_unit_test(${TEST_NAME} ${TEST_SOURCES})
