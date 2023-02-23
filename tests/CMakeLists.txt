# Include the unit_test.cmake script
include(unit_test.cmake)

# Add the Word_UT directory
add_subdirectory(Word_UT)
add_subdirectory(SafeQueue_UT)
add_subdirectory(WordList_UT)
add_subdirectory(WordProcessor_UT)

if(CODE_COVERAGE MATCHES ON)
    add_custom_target(coverage
        COMMAND lcov -c -i -d ${CMAKE_BINARY_DIR} -b ${CMAKE_SOURCE_DIR} --no-external -o cov_before.info
        COMMAND ctest
        COMMAND lcov -c -d ${CMAKE_BINARY_DIR} -b ${CMAKE_SOURCE_DIR} --no-external -o cov_after.info
        COMMAND lcov -a cov_before.info -a cov_after.info -o cov.info
        COMMAND genhtml -o ${CMAKE_SOURCE_DIR}/_test_coverage/html cov.info
    )
endif()
