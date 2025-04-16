cmake_minimum_required(VERSION 3.24)

project(dogontheroof
        VERSION 0.1
        LANGUAGES CXX C
        )

# glob src/ for .cc files
file(GLOB_RECURSE SRC_FILES src/*.cc)
add_executable(dogontheroof ${SRC_FILES})

set_target_properties(dogontheroof PROPERTIES CXX_STANDARD 23)
set_target_properties(dogontheroof PROPERTIES CXX_STANDARD_REQUIRED ON)
set_target_properties(dogontheroof PROPERTIES CXX_EXTENSIONS OFF)
set_target_properties(dogontheroof PROPERTIES COMPILE_WARNING_AS_ERROR ON)

target_include_directories(dogontheroof 
        PRIVATE
        src
        wgpu-native/ffi
        wgpu-native/ffi/webgpu-headers
        )

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Linking wgpu debug")
    target_link_directories(dogontheroof
            PRIVATE
            wgpu-native/target/debug
            )
else()
    message(STATUS "Linking wgpu release")
    target_link_directories(dogontheroof
            PRIVATE
            wgpu-native/target/release
            )
endif()
target_link_libraries(dogontheroof
        PRIVATE
        wgpu_native
        )

# set APOSBUILDDEBUG if debug
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Setting APOSBUILDDEBUG")
    target_compile_definitions(dogontheroof
            PRIVATE
            APOSBUILDDEBUG
            )
endif()

# precompiled headers
target_precompile_headers(dogontheroof
        PRIVATE
        src/ApostatePCH.h
        )

# glfw
add_subdirectory(glfw)
target_link_libraries(dogontheroof
        PRIVATE
        glfw
        )
target_include_directories(dogontheroof
        PRIVATE
        glfw/include
        )