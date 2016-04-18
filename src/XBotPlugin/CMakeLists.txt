# CMake minimum version and policies
cmake_minimum_required(VERSION 2.8.12)
if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 OLD)
    cmake_policy(SET CMP0005 NEW)
    cmake_policy(SET CMP0017 NEW)
endif(COMMAND cmake_policy)

# XBotPlugin
project(XBotPlugin)

# C++11 
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-std=c++11" COMPILER_SUPPORTS_CXX11)
check_cxx_compiler_flag("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

# include 
include_directories(../include)

# lib
add_library(XBotTestPlugin SHARED
    XBotTestPlugin.cpp
)
# lib
add_library(XBotCubicTrajectoryGenerator SHARED
    XBotCubicTrajectoryGenerator.cpp
)

# link the common libs
target_link_libraries(XBotTestPlugin XBotPluginHandler)
target_link_libraries(XBotCubicTrajectoryGenerator XBotPluginHandler)


# install lib and include
install(TARGETS XBotTestPlugin RUNTIME LIBRARY DESTINATION lib)
install(TARGETS XBotCubicTrajectoryGenerator RUNTIME LIBRARY DESTINATION lib)

install(DIRECTORY include/ 
        DESTINATION include
        FILES_MATCHING PATTERN "*.h*")