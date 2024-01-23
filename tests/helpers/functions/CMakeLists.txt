set(TEST_EXECUTABLE_NAME helperFunctionsTests)
set(TEST_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/tests.cpp)

add_executable(${TEST_EXECUTABLE_NAME} ${TEST_SOURCE})

target_link_libraries(${TEST_EXECUTABLE_NAME} PUBLIC ${HELPER_FUNCTIONS} Catch2::Catch2WithMain)