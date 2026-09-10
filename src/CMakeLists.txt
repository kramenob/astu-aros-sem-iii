cmake_minimum_required(VERSION 3.16)

project(AstuArosSemIII
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES x86_64)

# Build the application for Intel x86_64.
set(CMAKE_OSX_ARCHITECTURES x86_64)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

# Exclude templates.
list(FILTER SOURCES EXCLUDE REGEX "/labs/template/")
list(FILTER SOURCES EXCLUDE REGEX "/sels/template/")
list(FILTER SOURCES EXCLUDE REGEX "/\\.output/")

add_executable(AstuArosSemIII
    ${SOURCES}
)

target_include_directories(AstuArosSemIII
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)