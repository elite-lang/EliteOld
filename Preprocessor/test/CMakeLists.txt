enable_testing()
find_package(GTest REQUIRED)

include_directories (${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../include)
include_directories (${GTEST_INCLUDE_DIRS})
file(GLOB_RECURSE test_source_files ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable (pp_test ${test_source_files})

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../extlib)

target_link_libraries(pp_test preprocessor lua ${GTEST_BOTH_LIBRARIES} pthread)

add_test(EstringTest pp_test)

add_custom_target( runtest ALL DEPENDS pp_test)

add_custom_command(TARGET runtest
                   POST_BUILD
               COMMAND pp_test)
