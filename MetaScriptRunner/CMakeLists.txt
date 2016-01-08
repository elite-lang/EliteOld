cmake_minimum_required(VERSION 2.8)
project(MetaScriptRunner)

if (NOT BUILD_ALL)
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

include_directories(lib
					../Lex/include 
					../LR_Scanner/include 
					../RedApple/includes)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
endif()




# 核心路径配置
include_directories(src include)
file(GLOB_RECURSE source_files ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
list(REMOVE_ITEM  source_files ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

if(USE_DYNAMIC)
	add_library(meta SHARED ${source_files}) # 使用动态库
else()
	add_library(meta STATIC ${source_files}) # 使用静态库
endif()



if (NOT BUILD_ALL)

add_executable(toolua ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(toolua meta oolua lua dl lex scanner red)

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs 
    support core irreader executionengine interpreter 
    mc mcjit bitwriter x86codegen target)

# Link against LLVM libraries
target_link_libraries(toolua ${llvm_libs})

endif()
