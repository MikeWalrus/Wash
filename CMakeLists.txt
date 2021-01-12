cmake_minimum_required(VERSION 2.6)

project(wash)

message("Project Name: " ${PROJECT_NAME})

#设置编译参数
set(CMAKE_C_FLAGS "-g -Wall")

#设置执行文件输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 添加头文件路径
include_directories(${PROJECT_SOURCE_DIR}/src/include)

# 递归获取目录下所有的C文件
file(GLOB_RECURSE c_files ${PROJECT_SOURCE_DIR}/src/*.c)

# 生成执行文件
add_executable(${PROJECT_NAME} ${c_files})