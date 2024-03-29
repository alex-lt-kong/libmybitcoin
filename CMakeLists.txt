cmake_minimum_required(VERSION 3.18.4)

project(LIBMYBITCOIN)

find_library(SPDLOG_LIB spdlog)
if(NOT SPDLOG_LIB)
    message(
        FATAL_ERROR
        "spdlog library not found, install it with 'apt install libspdlog-dev'"
    )
endif()

option(BUILD_ASAN "Build with AddressSanitizer to detect memory error" OFF)
option(BUILD_UBSAN "Build with UndefinedBehaviorSanitizer to detect undefined behavior" OFF)

set(COUNTER 0)
set(ALL_OPTIONS BUILD_ASAN;BUILD_MSAN)
foreach(option IN LISTS ALL_OPTIONS)
    if(${option})
        math(EXPR COUNTER "${COUNTER}+1")
    endif()
endforeach()

if(${COUNTER} GREATER 1)
    message(FATAL_ERROR "Can't enable AddressSanitizer(BUILD_ASAN=ON), "
        "UndefinedBehaviorSanitizer(BUILD_UBSAN=ON) concurrently")
endif()


set(SANITIZER_NAME "None")
if(BUILD_ASAN)
    message("-- AddressSanitizer WILL be compiled in as BUILD_ASAN=ON")
    add_compile_options(-fsanitize=address -fno-omit-frame-pointer -g)
    add_link_options(-fsanitize=address)
    set(SANITIZER_NAME "AddressSanitizer")
    add_definitions(-DSANITIZER_NAME="${SANITIZER_NAME}")    
else()
    message("-- AddressSanitizer will NOT be compiled in as BUILD_ASAN=OFF")
endif()
if(BUILD_UBSAN)
    message("-- UndefinedBehaviorSanitizer WILL be compiled in as BUILD_UBSAN=ON")
    add_compile_options(-fsanitize=undefined -g)
    add_link_options(-fsanitize=undefined)
    set(SANITIZER_NAME "UndefinedBehaviorSanitizer")
    add_definitions(-DSANITIZER_NAME="${SANITIZER_NAME}")
else()
    message("-- UndefinedBehaviorSanitizer will NOT be compiled in as BUILD_UBSAN=OFF")
endif()


add_compile_options(-Wall -Wextra -pedantic -O3)


add_subdirectory(src/mybitcoin)
add_subdirectory(src/chapter-test)
add_subdirectory(src/continuous-testing)
