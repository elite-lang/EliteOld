cmake_minimum_required(VERSION 2.8)
project(lex)
SET(CMAKE_CXX_COMPILER_ENV_VAR "clang++")
SET(CMAKE_CXX_FLAGS "-std=c++11")
include_directories(include)
file(GLOB_RECURSE lex_source_files "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(lex STATIC ${lex_source_files}) 
add_executable(lextest ${lex_source_files})

find_package(PkgConfig)
pkg_check_modules(GLIBMM glibmm-2.4)
link_directories(${GLIBMM_LIBRARY_DIRS})
include_directories(${GLIBMM_INCLUDE_DIRS})
target_link_libraries(lextest ${GLIBMM_LIBRARIES})


FIND_PACKAGE(Doxygen)  
OPTION(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" ${DOXYGEN_FOUND})  
  
IF(BUILD_DOCUMENTATION)  
    IF(NOT DOXYGEN_FOUND)  
        MESSAGE(FATAL_ERROR "Doxygen is needed to build the documentation.")  
    ENDIF()  
  
    SET(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)  
    SET(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)  
  
    CONFIGURE_FILE(${doxyfile_in} ${doxyfile} @ONLY)  
  
    ADD_CUSTOM_TARGET(doc  
        COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}  
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}  
        COMMENT "Generating API documentation with Doxygen"  
        VERBATIM)  
  
    INSTALL(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION share/doc)  
ENDIF()  
