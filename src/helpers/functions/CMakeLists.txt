add_library(${HELPER_FUNCTIONS} STATIC functions.cpp)

target_include_directories(${HELPER_FUNCTIONS} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/../constants
	${CMAKE_CURRENT_SOURCE_DIR}/../../NonPlayer
	${CMAKE_CURRENT_SOURCE_DIR}/../../Player
	${CMAKE_CURRENT_SOURCE_DIR}/../../Grid
)