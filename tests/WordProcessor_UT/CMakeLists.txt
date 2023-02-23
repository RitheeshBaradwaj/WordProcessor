# List of source files for the unit test
set(TEST_NAME WordProcessor_UT)
set(TEST_SOURCES
    ${TEST_NAME}.cpp
    ${CMAKE_SOURCE_DIR}/src/wordtool/word.cpp
    ${CMAKE_SOURCE_DIR}/src/wordtool/word_list.cpp
    ${CMAKE_SOURCE_DIR}/src/wordtool/safe_queue.cpp
    ${CMAKE_SOURCE_DIR}/src/wordtool/word_processor.cpp
)

# Add the unit test executable
add_unit_test(${TEST_NAME} ${TEST_SOURCES})
