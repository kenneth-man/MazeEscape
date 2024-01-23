add_library(${NONPLAYER} INTERFACE)

target_include_directories(${NONPLAYER} INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/../helpers/constants
)