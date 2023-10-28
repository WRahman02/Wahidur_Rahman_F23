set(HEADER_FILES
	include/Platinum.h
	PlatinumApp.h
	Utilities.h
)

set(SOURCE_FILES
	placeholder.cpp
)

add_definitions(-DPL_DEBUG=2)
add_definitions(-DPLATINUM_LIB)

if(WIN32)
	add_definitions(-DPLATINUM_MSCPP)
elseif(LINUX)
	add_definitions(-DPLATINUM_LINUX)
elseif(APPLE)
	add_definitions(-DPLATINUM_APPLE)
endif()


add_library(Platinum SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Platinum PRIVATE pch.h)