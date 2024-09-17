cmake_minimum_required(VERSION 3.16)
project(windows)

# 取出当前目录中所有的源文件，存储到一个变量里 搜索目录，保存的变量
aux_source_directory(./ SRC)

# 搜索头文件和UI文件
file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/*.h)
file(GLOB UIS ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)

# 把源文件制作成静态库 库名，动/静态库，制作库的源文件
add_library(windows STATIC ${SRC} ${HEADERS} ${UIS})

target_link_libraries(windows PRIVATE
    Qt5::Core
    Qt5::Widgets
    Qt5::Multimedia
)
