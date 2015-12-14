cmake_minimum_required(VERSION 2.8)
project(ExIconv)

SET (CMAKE_CXX_COMPILER_ENV_VAR "clang")
SET (CMAKE_CXX_FLAGS "-std=c99")
SET (CMAKE_CXX_FLAGS_DEBUG   "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL  "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE  "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(src include lib/charsetdetect_include lib/iconv_include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

file(GLOB_RECURSE source_files ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

add_executable(iconv_test ${source_files})
add_library(exiconv STATIC ${source_files})
target_link_libraries(iconv_test iconv charsetdetect)
target_link_libraries(exiconv iconv charsetdetect)


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
