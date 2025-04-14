cmake_minimum_required(VERSION 3.24)

project(dogontheroof
        VERSION 0.1
        LANGUAGES CXX C
        )

add_executable(dogontheroof src/main.cc)

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