add_library(${GRID} STATIC Grid.cpp)

target_include_directories(${GRID} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/../Player
	${CMAKE_CURRENT_SOURCE_DIR}/../helpers/constants
)