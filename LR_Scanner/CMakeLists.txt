cmake_minimum_required(VERSION 2.8)

project(scanner)
SET(CMAKE_CXX_COMPILER_ENV_VAR "clang++")
SET(CMAKE_CXX_FLAGS "-std=c++11")
include_directories(includes build src lib/lua_include lib/lex_include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

# bison and flex
find_package(BISON)
find_package(FLEX)
flex_target(SCANNER src/scanner.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp COMPILE_FLAGS -w)
bison_target(PARSER src/parser.y  ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
ADD_FLEX_BISON_DEPENDENCY(SCANNER PARSER)

# src files and make exe
file(GLOB_RECURSE source_files "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(scannertest
	${source_files}
	${BISON_PARSER_OUTPUTS}
	${FLEX_SCANNER_OUTPUTS})

add_library(scanner STATIC ${source_files} ${BISON_PARSER_OUTPUTS} ${FLEX_SCANNER_OUTPUTS})

TARGET_LINK_LIBRARIES(scannertest lex lua dl)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# doxygen
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
