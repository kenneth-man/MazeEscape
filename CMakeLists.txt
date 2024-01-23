# Default cmake version
cmake_minimum_required(VERSION 3.26.3)

# Name of project
project(
	MazeEscape
	VERSION 1.0.0
	LANGUAGES C CXX
)

# Override Pre-defined Variables
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Custom Global Variables
set(ACTIONS actions)
set(GRID grid)
set(HELPER_CONSTANTS helperConstants)
set(HELPER_FUNCTIONS helperFunctions)
set(NONPLAYER nonPlayer)
set(PLAYER player)
set(TITLESCREEN titleScreen)
set(EXECUTABLE_NAME mazeEscape)

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

# Let CMake know about our subdirectory `CMakeLists.txt` files
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(app)