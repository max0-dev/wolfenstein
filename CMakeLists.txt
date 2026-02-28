cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(template VERSION 0.1.0 LANGUAGES C CXX)

find_package(fmt CONFIG REQUIRED)

add_executable(template main.cpp)

function(set_output_dirs target)
    set_target_properties(${target} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/bin
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/lib
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/lib
    )
endfunction()

target_link_libraries(template PRIVATE fmt::fmt)

set_output_dirs(template)