cmake_minimum_required(VERSION 3.14)
project(video-app C CXX)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/glfw)

list(APPEND SOURCES src/main.cpp)

# YOU NEED THIS TO MAKE THE DEPRECATED OpenGL WORK
if(APPLE)
	list(APPEND EXTRA_LIBS "-framework OpenGL")
elseif(WIN32)
	list(APPEND EXTRA_LIBS "-lglu32 -lopengl32")
	set(CMAKE_EXE_LINKER_FLAGS "-std=gnu99 -static -static-libgcc -static-libstdc++ -mwindows")
else()#LINUX
	list(APPEND EXTRA_LIBS "-lGl -lGLU -lX11")
endif()

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} glfw ${EXTRA_LIBS})
