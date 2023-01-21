project(AutoDash.Lighting CXX)
cmake_minimum_required(VERSION 3.7.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(RESOURCES_DIR ${ROOT_DIR}/resources)
set(SOURCE_DIR ${ROOT_DIR}/source)
set(INCLUDE_DIR ${ROOT_DIR}/include)
set(COMMON_INCLUDE_DIR ${ROOT_DIR}/../../common/include)
set(COMMON_SOURCE_DIR ${ROOT_DIR}/../../common/source)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ROOT_DIR}/module)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules/")
SET(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -rdynamic)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_INIT} -Wall -fPIC")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-g -O3")

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-psabi")
endif()

add_definitions(-DBOOST_ALL_DYN_LINK)

find_package(Qt5 COMPONENTS WebEngineWidgets Widgets Svg REQUIRED)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

file(GLOB_RECURSE source_files ${COMMON_SOURCE_DIR}/*.cpp ${COMMON_INCLUDE_DIR}/*.hpp ${INCLUDE_DIR}/*.hpp ${SOURCE_DIR}/*.cpp ${RESOURCES_DIR}/*.qrc)

add_library(AutoDash.Lighting SHARED ${source_files})

target_include_directories(AutoDash.Lighting PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${INCLUDE_DIR}
    ${COMMON_INCLUDE_DIR}
    )

target_include_directories(AutoDash.Lighting SYSTEM PRIVATE
    ${Qt5Svg_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
    ${Qt5WebEngineWidgets_INCLUDE_DIRS}
    )

target_link_libraries(AutoDash.Lighting
    ${Qt5Svg_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
    ${Qt5WebEngineWidgets_LIBRARIES}
    )
