# Create library for file
add_library(${ACTIONS} STATIC Actions.cpp)

# Specify the `.h` files for the target library
target_include_directories(${ACTIONS} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/../Grid
	${CMAKE_CURRENT_SOURCE_DIR}/../Player
	${CMAKE_CURRENT_SOURCE_DIR}/../helpers/constants
)