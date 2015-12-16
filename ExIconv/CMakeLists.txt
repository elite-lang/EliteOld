cmake_minimum_required(VERSION 2.8)
project(ExIconv)

if(NOT BUILD_ALL)
  
SET (CMAKE_CXX_COMPILER_ENV_VAR "clang++")
SET (CMAKE_CXX_FLAGS "-std=c++11")
SET (CMAKE_CXX_FLAGS_DEBUG   "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL  "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE  "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(../extlib/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../extlib/lib)
  
endif()


include_directories(src include)

file(GLOB_RECURSE source_files ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(exiconv STATIC ${source_files})
target_link_libraries(exiconv iconv charsetdetect)


if(NOT BUILD_ALL)
    add_subdirectory(test)
endif()