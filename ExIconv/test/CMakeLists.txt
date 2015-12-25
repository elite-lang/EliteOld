enable_testing()
find_package(GTest REQUIRED)

include_directories (${CMAKE_CURRENT_SOURCE_DIR}) 
include_directories (${GTEST_INCLUDE_DIRS})
file(GLOB_RECURSE test_source_files ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable (estring_test ${test_source_files})

target_link_libraries(estring_test exiconv iconv charsetdetect ${GTEST_BOTH_LIBRARIES} pthread)

add_test(EstringTest estring_test)

add_custom_target( runtest ALL
                   DEPENDS estring_test)

add_custom_command(TARGET runtest
                   POST_BUILD
                   COMMAND estring_test)