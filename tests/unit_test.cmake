find_package(GTest REQUIRED)
find_library(LLVM_PROFILE_LIBRARY LLVMProfile)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${GMOCK_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)
set(TEST_BINARY_DIR ${CMAKE_SOURCE_DIR}/_bin/tests/bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")

function(add_unit_test target_name)
    set(sources ${ARGN})
    message("sources:${sources}")
    add_executable(${target_name} ${sources})
    target_link_libraries(${target_name}
        ${GTEST_LIBRARY}
        ${GTEST_MAIN_LIBRARY}
        pthread
        gcov
    )

    if(CODE_COVERAGE MATCHES ON)
        target_compile_options(${target_name} PUBLIC --coverage)
    endif()

    add_test(
        NAME ${target_name}
        COMMAND ${target_name} --gtest_output=xml:${CMAKE_SOURCE_DIR}/_test_reports/${target_name}.xml
    )

    set_target_properties(${target_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TEST_BINARY_DIR})
    install(TARGETS ${target_name} DESTINATION ${TEST_BINARY_DIR})
endfunction()
