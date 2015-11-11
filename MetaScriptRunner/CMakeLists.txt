cmake_minimum_required(VERSION 2.8)
project(TestOOLua)

set(LLVM_TARGETS_TO_BUILD X86)
set(LLVM_BUILD_RUNTIME OFF)
set(LLVM_BUILD_TOOLS OFF)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")


SET (CMAKE_CXX_COMPILER_ENV_VAR "clang++")
SET (CMAKE_CXX_FLAGS "-std=c++11")
SET (CMAKE_CXX_FLAGS_DEBUG   "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL  "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE  "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(src include lib lib/lex lib/scanner lib/redapple)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

file(GLOB_RECURSE source_files ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(meta STATIC ${source_files})

add_executable(toolua ${source_files})
target_link_libraries(toolua oolua lua dl lex scanner red)

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs 
    support core irreader executionengine interpreter 
    mc mcjit bitwriter x86codegen target)

# Link against LLVM libraries
target_link_libraries(toolua ${llvm_libs})


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
