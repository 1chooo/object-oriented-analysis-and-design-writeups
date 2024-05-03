cmake_minimum_required(VERSION 3.26)
project(calculator VERSION 0.0.1 DESCRIPTION "A simple calculator")
# project(calculator PROJECT_DESCRIPTION "A simple calculator")

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)  # 添加 inc 目錄以便能夠找到 .h 檔案

add_executable(calculator src/main.cpp src/calc.cpp)