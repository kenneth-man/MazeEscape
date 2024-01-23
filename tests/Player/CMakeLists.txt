set(TEST_EXECUTABLE_NAME playerTests)
set(TEST_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/tests.cpp)

add_executable(${TEST_EXECUTABLE_NAME} ${TEST_SOURCE})

target_link_libraries(${TEST_EXECUTABLE_NAME} PUBLIC ${PLAYER} Catch2::Catch2WithMain)