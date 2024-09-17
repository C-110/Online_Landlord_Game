cmake_minimum_required(VERSION 3.16)
project(tcp)

# 取出当前目录中所有的源文件，存储到一个变量里 搜索目录，保存的变量
aux_source_directory(./ SRC)

# 搜索头文件
file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/*.h)

# 把源文件制作成静态库 库名，动/静态库，制作库的源文件
add_library(tcp STATIC ${SRC} ${HEADERS})

# 链接库，Windows的socket编程依赖库
target_link_libraries(tcp PRIVATE Qt5::Core Ws2_32)
