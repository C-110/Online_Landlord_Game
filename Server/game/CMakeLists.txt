cmake_minimum_required(VERSION 3.16)
project(game)
set(CMAKE_CXX_STANDARD 17)

# 取出当前目录中所有的源文件，存储到一个变量里 搜索目录，保存的变量
aux_source_directory(./ SRC)
# 把源文件制作成静态库 库名，动/静态库，制作库的源文件
add_library(game STATIC ${SRC}
        Room.cpp
        Room.h
        RoomList.cpp
        RoomList.h)
#target_link_libraries(game mycrypto)
target_link_libraries(game common hiredis redis++)
