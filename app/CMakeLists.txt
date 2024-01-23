# Create executable
add_executable(${EXECUTABLE_NAME} main.cpp)

# Link libraries with executable
target_link_libraries(${EXECUTABLE_NAME} PUBLIC
	${ACTIONS}
	${GRID}
	${HELPER_CONSTANTS}
	${HELPER_FUNCTIONS}
	${NONPLAYER}
	${PLAYER}
	${TITLESCREEN}
)