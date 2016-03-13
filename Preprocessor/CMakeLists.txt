cmake_minimum_required(VERSION 2.8)
project(Preprocessor)

if(NOT BUILD_ALL) # BUILD_ALL负责确认是不是所有子项目统一配置构建
SET (CMAKE_BUILD_TYPE Debug)
SET (CMAKE_CXX_COMPILER_ENV_VAR "clang++")
SET (CMAKE_CXX_FLAGS "-std=c++11")
SET (CMAKE_CXX_FLAGS_DEBUG   "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL  "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE  "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
endif()


# 核心路径配置
include_directories(include src ../extlib/include)
file(GLOB_RECURSE source_files ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
if(USE_DYNAMIC)
	add_library(builder SHARED ${source_files}) # 使用动态库
else()
	add_library(builder STATIC ${source_files}) # 使用静态库
endif()
