set(HEADER_FILES
	include/Platinum.h
	PlatinumApp.h
	Utilities.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
)

set(SOURCE_FILES
	WindowImplementation.cpp
	GLFWCode/GLFWImplementation.cpp
)

add_definitions(-DPL_DEBUG=2)
add_definitions(-DPLATINUM_LIB)


include_directories(${PROJECT_SOURCE_DIR})
include_directories(../glfw/include)

add_library(Platinum SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Platinum PRIVATE pch.h)

target_link_libraries(Platinum glfw)