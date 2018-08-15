cmake_minimum_required (VERSION 2.6)

project(engine)

# add includes
include_directories(${CMAKE_CURRENT_LIST_DIR}/../lib/glfw/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/../lib/glew/include)
include_directories(${CMAKE_CURRENT_LIST_DIR})

# link libraries
link_directories(${CMAKE_CURRENT_LIST_DIR}/../lib/glfw/lib)
link_directories(${CMAKE_CURRENT_LIST_DIR}/../lib/glfw/lib)

aux_source_directory(render render_src)
aux_source_directory(common common_src)
aux_source_directory(glm, glm_src)
add_executable(engine
        main.cpp
        ${render_src}
        ${common_src}
        ${glm_src}
)

# target link
target_link_libraries(engine glfw3)
target_link_libraries(engine glew)

if(APPLE)
	find_library(OPENGL OPENGL)
	find_library(COCOA Cocoa)
	find_library(IOKIT IOKit)
	find_library(COREVIDEO CoreVideo)

	target_link_libraries(engine ${OPENGL})
	target_link_libraries(engine ${COCOA})
	target_link_libraries(engine ${IOKIT})
	target_link_libraries(engine ${COREVIDEO})
endif()