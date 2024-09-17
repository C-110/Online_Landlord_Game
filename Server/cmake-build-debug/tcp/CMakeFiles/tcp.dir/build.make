# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/s/Online_LandlordGame/Server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/s/Online_LandlordGame/Server/cmake-build-debug

# Include any dependencies generated for this target.
include tcp/CMakeFiles/tcp.dir/depend.make

# Include the progress variables for this target.
include tcp/CMakeFiles/tcp.dir/progress.make

# Include the compile flags for this target's objects.
include tcp/CMakeFiles/tcp.dir/flags.make

tcp/CMakeFiles/tcp.dir/TcpConnection.cpp.o: tcp/CMakeFiles/tcp.dir/flags.make
tcp/CMakeFiles/tcp.dir/TcpConnection.cpp.o: ../tcp/TcpConnection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/s/Online_LandlordGame/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tcp/CMakeFiles/tcp.dir/TcpConnection.cpp.o"
	cd /mnt/s/Online_LandlordGame/Server/cmake-build-debug/tcp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tcp.dir/TcpConnection.cpp.o -c /mnt/s/Online_LandlordGame/Server/tcp/TcpConnection.cpp

tcp/CMakeFiles/tcp.dir/TcpConnection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tcp.dir/TcpConnection.cpp.i"
	cd /mnt/s/Online_LandlordGame/Server/cmake-build-debug/tcp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/s/Online_LandlordGame/Server/tcp/TcpConnection.cpp > CMakeFiles/tcp.dir/TcpConnection.cpp.i

tcp/CMakeFiles/tcp.dir/TcpConnection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tcp.dir/TcpConnection.cpp.s"
	cd /mnt/s/Online_LandlordGame/Server/cmake-build-debug/tcp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/s/Online_LandlordGame/Server/tcp/TcpConnection.cpp -o CMakeFiles/tcp.dir/TcpConnection.cpp.s

tcp/CMakeFiles/tcp.dir/TcpServer.cpp.o: tcp/CMakeFiles/tcp.dir/flags.make
tcp/CMakeFiles/tcp.dir/TcpServer.cpp.o: ../tcp/TcpServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/s/Online_LandlordGame/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tcp/CMakeFiles/tcp.dir/TcpServer.cpp.o"
	cd /mnt/s/Online_LandlordGame/Server/cmake-build-debug/tcp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tcp.dir/TcpServer.cpp.o -c /mnt/s/Online_LandlordGame/Server/tcp/TcpServer.cpp

tcp/CMakeFiles/tcp.dir/TcpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tcp.dir/TcpServer.cpp.i"
	cd /mnt/s/Online_LandlordGame/Server/cmake-build-debug/tcp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/s/Online_LandlordGame/Server/tcp/TcpServer.cpp > CMakeFiles/tcp.dir/TcpServer.cpp.i

tcp/CMakeFiles/tcp.dir/TcpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tcp.dir/TcpServer.cpp.s"
	cd /mnt/s/Online_LandlordGame/Server/cmake-build-debug/tcp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/s/Online_LandlordGame/Server/tcp/TcpServer.cpp -o CMakeFiles/tcp.dir/TcpServer.cpp.s

# Object files for target tcp
tcp_OBJECTS = \
"CMakeFiles/tcp.dir/TcpConnection.cpp.o" \
"CMakeFiles/tcp.dir/TcpServer.cpp.o"

# External object files for target tcp
tcp_EXTERNAL_OBJECTS =

tcp/libtcp.a: tcp/CMakeFiles/tcp.dir/TcpConnection.cpp.o
tcp/libtcp.a: tcp/CMakeFiles/tcp.dir/TcpServer.cpp.o
tcp/libtcp.a: tcp/CMakeFiles/tcp.dir/build.make
tcp/libtcp.a: tcp/CMakeFiles/tcp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/s/Online_LandlordGame/Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libtcp.a"
	cd /mnt/s/Online_LandlordGame/Server/cmake-build-debug/tcp && $(CMAKE_COMMAND) -P CMakeFiles/tcp.dir/cmake_clean_target.cmake
	cd /mnt/s/Online_LandlordGame/Server/cmake-build-debug/tcp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tcp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tcp/CMakeFiles/tcp.dir/build: tcp/libtcp.a

.PHONY : tcp/CMakeFiles/tcp.dir/build

tcp/CMakeFiles/tcp.dir/clean:
	cd /mnt/s/Online_LandlordGame/Server/cmake-build-debug/tcp && $(CMAKE_COMMAND) -P CMakeFiles/tcp.dir/cmake_clean.cmake
.PHONY : tcp/CMakeFiles/tcp.dir/clean

tcp/CMakeFiles/tcp.dir/depend:
	cd /mnt/s/Online_LandlordGame/Server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/s/Online_LandlordGame/Server /mnt/s/Online_LandlordGame/Server/tcp /mnt/s/Online_LandlordGame/Server/cmake-build-debug /mnt/s/Online_LandlordGame/Server/cmake-build-debug/tcp /mnt/s/Online_LandlordGame/Server/cmake-build-debug/tcp/CMakeFiles/tcp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tcp/CMakeFiles/tcp.dir/depend

