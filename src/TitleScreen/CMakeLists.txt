add_library(${TITLESCREEN} STATIC TitleScreen.cpp)

target_include_directories(${TITLESCREEN} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/../helpers
)