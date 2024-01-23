add_library(${PLAYER} STATIC Player.cpp)

target_include_directories(${PLAYER} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/../NonPlayer
	${CMAKE_CURRENT_SOURCE_DIR}/../helpers
)