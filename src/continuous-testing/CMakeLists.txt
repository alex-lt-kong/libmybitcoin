include_directories (${PROJECT_SOURCE_DIR}/src/) 

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

add_executable(script-test ./script-test.cpp)
add_executable(tx-test ./tx-test.cpp)
add_executable(aes ./aes.cpp)
target_link_libraries(script-test boost_random mycrypto mybitcoin)
target_link_libraries(tx-test boost_random mycrypto mybitcoin curl spdlog::spdlog)
target_link_libraries(aes crypto++)

find_library(CRYPTOPP_LIB crypto++)
if(NOT CRYPTOPP_LIB)
    message(FATAL_ERROR "crypto++ library not found, install it with 'apt install libcrypto++-dev'")
endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/script-test-driver.py
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../../)

add_custom_command(TARGET tx-test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:tx-test> ../../)
    add_custom_command(TARGET script-test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:script-test> ../../)
