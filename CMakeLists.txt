# Default cmake version
cmake_minimum_required(VERSION 3.26.3)

# Name of project
project(
	MazeEscape
	VERSION 1.0.0
	LANGUAGES C CXX
)

# Create executable
add_executable(${PROJECT_NAME} main.cpp)

# Set CMake to use C++17 compiler
target_compile_features(
	${PROJECT_NAME}
	PRIVATE
	cxx_std_17
)

# Custom Global Variables
set(ACTIONS actions)
set(GRID grid)
set(HELPER_CONSTANTS helperConstants)
set(HELPER_FUNCTIONS helperFunctions)
set(NONPLAYER nonPlayer)
set(PLAYER player)
set(TITLESCREEN titleScreen)

# Let CMake know about our subdirectory `CMakeLists.txt` files
add_subdirectory(src)
add_subdirectory(tests)

# Link libraries with executable
target_link_libraries(${PROJECT_NAME} PUBLIC
	${ACTIONS}
	${GRID}
	${HELPER_CONSTANTS}
	${HELPER_FUNCTIONS}
	${NONPLAYER}
	${PLAYER}
	${TITLESCREEN}
)

# Include `FetchContent` from Cmake
include(FetchContent)

# Clones the repository into `/build/_deps` directory
FetchContent_Declare(
	Catch2
	GIT_REPOSITORY https://github.com/catchorg/Catch2.git
	GIT_TAG v3.5.1
)

# Loads the repository into our project
FetchContent_MakeAvailable(Catch2)