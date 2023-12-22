set(HEADER_FILES
	include/Platinum.h
	PlatinumApp.h
	Events.h
	Utilities.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
	GLFWCode/OpenGLRenderer.h
	GLFWCode/OpenGLPicture.h
	GLFWCode/OpenGLShader.h
	Picture.h
	PictureImplementation.h
	Renderer.h
	RendererImplementation.h
	Shader.h
	ShaderImplementation.h
	Unit.h
	
)

set(SOURCE_FILES
	Events.cpp
	GameWindow.cpp
	GLFWCode/OpenGLRenderer.cpp
	GLFWCode/OpenGLPicture.cpp
	GLFWCode/OpenGLShader.cpp
	GLFWCode/GLFWImplementation.cpp
	Picture.cpp
	Renderer.cpp
	Shader.cpp
	Unit.cpp
)

add_definitions(-DPL_DEBUG=2)
add_definitions(-DPLATINUM_LIB)


include_directories(../Mystic)
include_directories(../glfw/include)
include_directories(../glad/include)
include_directories(../stbi)

add_library(Platinum SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Platinum PRIVATE pch.h)

target_link_libraries(Platinum glfw)
target_link_libraries(Platinum glad)
target_link_libraries(Platinum stbi)