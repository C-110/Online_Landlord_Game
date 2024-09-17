# 多级目录cmake编写
cmake_minimum_required(VERSION 3.16)
project(Server)

set(CMAKE_CXX_STANDARD 17)

#添加头文件路径
include_directories(
        ${PROJECT_SOURCE_DIR}/common
        ${PROJECT_SOURCE_DIR}/http
        ${PROJECT_SOURCE_DIR}/reactor
        ${PROJECT_SOURCE_DIR}/tcp
        ${PROJECT_SOURCE_DIR}/thread
        ${PROJECT_SOURCE_DIR}/serialize
        ${PROJECT_SOURCE_DIR}/crypto
        ${PROJECT_SOURCE_DIR}/game
        ${PROJECT_SOURCE_DIR}/database
        "/usr/local/ssl/include"
        "/usr/include/mysql"
        # 测试目录
        ${PROJECT_SOURCE_DIR}/test
)

# 添加子目录，每个子目录里有单独的cmake
add_subdirectory(common)
add_subdirectory(http)
add_subdirectory(reactor)
add_subdirectory(tcp)
add_subdirectory(thread)
add_subdirectory(serialize)
add_subdirectory(crypto)
add_subdirectory(game)
add_subdirectory(database)

# 测试子目录
add_subdirectory(test)

# 添加openssl动态库路径
link_directories(/usr/local/ssl/lib64/)

# 链接MySQL动态库路径
link_directories(/usr/lib/x86_64-linux-gnu/)
# 链接Jsoncpp动态库路径
link_directories(/usr/local/lib)

# 链接子目录中生成的静态库文件,静态库名称
link_libraries(tcp http reactor thread common test game mycrypto serialize database)

# 指定可执行程序的生成路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 生成可执行程序
add_executable(Server main.cpp)
