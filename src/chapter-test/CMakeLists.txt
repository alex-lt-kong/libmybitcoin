include_directories (${PROJECT_SOURCE_DIR}/src/) 

add_executable(test_ch01 ./test_ch01.cpp)
add_executable(test_ch02 ./test_ch02.cpp)
add_executable(test_ch03 ./test_ch03.cpp)
add_executable(test_ch04 ./test_ch04.cpp)
add_executable(test_ch05 ./test_ch05.cpp)
add_executable(test_ch06 ./test_ch06.cpp)

target_link_libraries(test_ch01 boost_random mycrypto mybitcoin)
target_link_libraries(test_ch02)
target_link_libraries(test_ch03 boost_random mycrypto mybitcoin)
target_link_libraries(test_ch04 boost_random mycrypto mybitcoin)
target_link_libraries(test_ch05 boost_random mycrypto mybitcoin)
target_link_libraries(test_ch06 boost_random mycrypto mybitcoin)

add_custom_target(test)

add_custom_command(TARGET test COMMAND test_ch01 COMMENT "Running test_ch01... (Sanitizer: ${SANITIZER_NAME})")
add_custom_command(TARGET test COMMAND test_ch02 COMMENT "Running test_ch02... (Sanitizer: ${SANITIZER_NAME})")
add_custom_command(TARGET test COMMAND test_ch03 COMMENT "Running test_ch03... (Sanitizer: ${SANITIZER_NAME})")
add_custom_command(TARGET test COMMAND test_ch04 COMMENT "Running test_ch04... (Sanitizer: ${SANITIZER_NAME})")
add_custom_command(TARGET test COMMAND test_ch05 COMMENT "Running test_ch05... (Sanitizer: ${SANITIZER_NAME})")
add_custom_command(TARGET test COMMAND test_ch06 COMMENT "Running test_ch06... (Sanitizer: ${SANITIZER_NAME})")
