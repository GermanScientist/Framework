# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (MyFramework)

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
	message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like 'build')" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

# Compile external dependencies
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

if(UNIX)
	set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -O2")

	# For leak-checking and profiling, add '-pg' to CXX flags
	# set(CMAKE_CXX_FLAGS "-Wall -pg -std=c++11 -O2")
	# valgrind --leak-check=full ./demo
	# ./demo # creates cmon.out
	# gprof demo gmon.out > analysis.txt
endif(UNIX)

if(WIN32)
	# Create a group for Visual Studio
	SOURCE_GROUP(MyFramework REGULAR_EXPRESSION ".*/myFramework/.*" )
	# suppress pedantic warnings
	add_definitions( "/W1 /D_CRT_SECURE_NO_WARNINGS /wd4514 /nologo" )
endif(WIN32)

add_definitions( # g++ -Dxxx
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

# Compile external dependencies
add_subdirectory (external)

include_directories( # g++ -Ipath/to/headerfiles
	external/glfw-3.3/include/
	external/glm-0.9.9.2/
	external/glew-1.9.0/include/
	.
)

link_directories( # g++ -Lpath/to/library

)

set(ALL_GRAPHICS_LIBS
	${OPENGL_LIBRARY}
	glfw
	GLEW_190
)

# MyFramework (libmyFramework.a)
add_library(myFramework # ar rcs libmyFramework.a
	myFramework/camera.h
	myFramework/camera.cpp
	myFramework/renderer.h
	myFramework/renderer.cpp
	myFramework/sprite.h
	myFramework/sprite.cpp
	myFramework/cube.h
	myFramework/cube.cpp
	myFramework/textureloader.h
	myFramework/textureloader.cpp
	myFramework/material.h
	myFramework/material.cpp
	myFramework/objloader.h
	myFramework/objloader.cpp
	myFramework/model.h
	myFramework/model.cpp
	myFramework/runner.h
	myFramework/runner.cpp
	myFramework/time.h
	myFramework/time.cpp
	myFramework/scene.cpp
	myFramework/scene.h
	myFramework/entity.cpp
	myFramework/entity.h
)

# Main
add_executable(main # g++ demo/main.cpp -o main
	demo/main.cpp
	demo/myScene.cpp
	demo/myScene.h
)
target_link_libraries(main # g++ -lmyFramework
	myFramework
	${ALL_GRAPHICS_LIBS}
)
# Copy assets and shaders to the build directory
# (In Visual Studio, copy these directories to either 'Release' or 'Build')
file(
	COPY demo/assets
	DESTINATION ${CMAKE_BINARY_DIR}
)
file(
	COPY myFramework/shaders
	DESTINATION ${CMAKE_BINARY_DIR}
)