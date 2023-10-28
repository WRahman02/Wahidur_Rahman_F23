set(HEADER_FILES
	
)

set(SOURCE_FILES
	main.cpp
)

add_library(Game_WA  ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(Game_WA Platinum)

include_directories(../Platinum/include)