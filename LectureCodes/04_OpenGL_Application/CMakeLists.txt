#需求的最低cmake版本
cmake_minimum_required(VERSION 3.12)

#工程名
project(OpenGL_Lecture)

#工程支持的C++版本
set(CMAKE_CXX_STANDARD 17)

#往项目中添加一个全局的预编译宏
add_definitions(-DDEBUG)

include_directories(
	SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/include
)

link_directories(
	SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/lib
)

add_subdirectory(wrapper)
add_subdirectory(application)

add_executable(openglStudy "main.cpp" "glad.c")

target_link_libraries(openglStudy glfw3.lib wrapper app)