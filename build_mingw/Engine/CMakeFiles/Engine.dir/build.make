# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\hp\Desktop\code\MyGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\hp\Desktop\code\MyGL\build_mingw

# Include any dependencies generated for this target.
include Engine/CMakeFiles/Engine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Engine/CMakeFiles/Engine.dir/compiler_depend.make

# Include the progress variables for this target.
include Engine/CMakeFiles/Engine.dir/progress.make

# Include the compile flags for this target's objects.
include Engine/CMakeFiles/Engine.dir/flags.make

Engine/CMakeFiles/Engine.dir/src/Engine/camera.cpp.obj: Engine/CMakeFiles/Engine.dir/flags.make
Engine/CMakeFiles/Engine.dir/src/Engine/camera.cpp.obj: Engine/CMakeFiles/Engine.dir/includes_CXX.rsp
Engine/CMakeFiles/Engine.dir/src/Engine/camera.cpp.obj: C:/Users/hp/Desktop/code/MyGL/Engine/src/Engine/camera.cpp
Engine/CMakeFiles/Engine.dir/src/Engine/camera.cpp.obj: Engine/CMakeFiles/Engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\hp\Desktop\code\MyGL\build_mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Engine/CMakeFiles/Engine.dir/src/Engine/camera.cpp.obj"
	cd /d C:\Users\hp\Desktop\code\MyGL\build_mingw\Engine && D:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Engine/CMakeFiles/Engine.dir/src/Engine/camera.cpp.obj -MF CMakeFiles\Engine.dir\src\Engine\camera.cpp.obj.d -o CMakeFiles\Engine.dir\src\Engine\camera.cpp.obj -c C:\Users\hp\Desktop\code\MyGL\Engine\src\Engine\camera.cpp

Engine/CMakeFiles/Engine.dir/src/Engine/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Engine.dir/src/Engine/camera.cpp.i"
	cd /d C:\Users\hp\Desktop\code\MyGL\build_mingw\Engine && D:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\hp\Desktop\code\MyGL\Engine\src\Engine\camera.cpp > CMakeFiles\Engine.dir\src\Engine\camera.cpp.i

Engine/CMakeFiles/Engine.dir/src/Engine/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/src/Engine/camera.cpp.s"
	cd /d C:\Users\hp\Desktop\code\MyGL\build_mingw\Engine && D:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\hp\Desktop\code\MyGL\Engine\src\Engine\camera.cpp -o CMakeFiles\Engine.dir\src\Engine\camera.cpp.s

Engine/CMakeFiles/Engine.dir/src/Engine/window.cpp.obj: Engine/CMakeFiles/Engine.dir/flags.make
Engine/CMakeFiles/Engine.dir/src/Engine/window.cpp.obj: Engine/CMakeFiles/Engine.dir/includes_CXX.rsp
Engine/CMakeFiles/Engine.dir/src/Engine/window.cpp.obj: C:/Users/hp/Desktop/code/MyGL/Engine/src/Engine/window.cpp
Engine/CMakeFiles/Engine.dir/src/Engine/window.cpp.obj: Engine/CMakeFiles/Engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\hp\Desktop\code\MyGL\build_mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Engine/CMakeFiles/Engine.dir/src/Engine/window.cpp.obj"
	cd /d C:\Users\hp\Desktop\code\MyGL\build_mingw\Engine && D:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Engine/CMakeFiles/Engine.dir/src/Engine/window.cpp.obj -MF CMakeFiles\Engine.dir\src\Engine\window.cpp.obj.d -o CMakeFiles\Engine.dir\src\Engine\window.cpp.obj -c C:\Users\hp\Desktop\code\MyGL\Engine\src\Engine\window.cpp

Engine/CMakeFiles/Engine.dir/src/Engine/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Engine.dir/src/Engine/window.cpp.i"
	cd /d C:\Users\hp\Desktop\code\MyGL\build_mingw\Engine && D:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\hp\Desktop\code\MyGL\Engine\src\Engine\window.cpp > CMakeFiles\Engine.dir\src\Engine\window.cpp.i

Engine/CMakeFiles/Engine.dir/src/Engine/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/src/Engine/window.cpp.s"
	cd /d C:\Users\hp\Desktop\code\MyGL\build_mingw\Engine && D:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\hp\Desktop\code\MyGL\Engine\src\Engine\window.cpp -o CMakeFiles\Engine.dir\src\Engine\window.cpp.s

Engine/CMakeFiles/Engine.dir/3rdparty/stb_image/stb_image.cpp.obj: Engine/CMakeFiles/Engine.dir/flags.make
Engine/CMakeFiles/Engine.dir/3rdparty/stb_image/stb_image.cpp.obj: Engine/CMakeFiles/Engine.dir/includes_CXX.rsp
Engine/CMakeFiles/Engine.dir/3rdparty/stb_image/stb_image.cpp.obj: C:/Users/hp/Desktop/code/MyGL/Engine/3rdparty/stb_image/stb_image.cpp
Engine/CMakeFiles/Engine.dir/3rdparty/stb_image/stb_image.cpp.obj: Engine/CMakeFiles/Engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\hp\Desktop\code\MyGL\build_mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Engine/CMakeFiles/Engine.dir/3rdparty/stb_image/stb_image.cpp.obj"
	cd /d C:\Users\hp\Desktop\code\MyGL\build_mingw\Engine && D:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Engine/CMakeFiles/Engine.dir/3rdparty/stb_image/stb_image.cpp.obj -MF CMakeFiles\Engine.dir\3rdparty\stb_image\stb_image.cpp.obj.d -o CMakeFiles\Engine.dir\3rdparty\stb_image\stb_image.cpp.obj -c C:\Users\hp\Desktop\code\MyGL\Engine\3rdparty\stb_image\stb_image.cpp

Engine/CMakeFiles/Engine.dir/3rdparty/stb_image/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Engine.dir/3rdparty/stb_image/stb_image.cpp.i"
	cd /d C:\Users\hp\Desktop\code\MyGL\build_mingw\Engine && D:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\hp\Desktop\code\MyGL\Engine\3rdparty\stb_image\stb_image.cpp > CMakeFiles\Engine.dir\3rdparty\stb_image\stb_image.cpp.i

Engine/CMakeFiles/Engine.dir/3rdparty/stb_image/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/3rdparty/stb_image/stb_image.cpp.s"
	cd /d C:\Users\hp\Desktop\code\MyGL\build_mingw\Engine && D:\Qt\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\hp\Desktop\code\MyGL\Engine\3rdparty\stb_image\stb_image.cpp -o CMakeFiles\Engine.dir\3rdparty\stb_image\stb_image.cpp.s

# Object files for target Engine
Engine_OBJECTS = \
"CMakeFiles/Engine.dir/src/Engine/camera.cpp.obj" \
"CMakeFiles/Engine.dir/src/Engine/window.cpp.obj" \
"CMakeFiles/Engine.dir/3rdparty/stb_image/stb_image.cpp.obj"

# External object files for target Engine
Engine_EXTERNAL_OBJECTS =

Engine/libEngine.a: Engine/CMakeFiles/Engine.dir/src/Engine/camera.cpp.obj
Engine/libEngine.a: Engine/CMakeFiles/Engine.dir/src/Engine/window.cpp.obj
Engine/libEngine.a: Engine/CMakeFiles/Engine.dir/3rdparty/stb_image/stb_image.cpp.obj
Engine/libEngine.a: Engine/CMakeFiles/Engine.dir/build.make
Engine/libEngine.a: Engine/CMakeFiles/Engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\hp\Desktop\code\MyGL\build_mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libEngine.a"
	cd /d C:\Users\hp\Desktop\code\MyGL\build_mingw\Engine && $(CMAKE_COMMAND) -P CMakeFiles\Engine.dir\cmake_clean_target.cmake
	cd /d C:\Users\hp\Desktop\code\MyGL\build_mingw\Engine && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Engine.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Engine/CMakeFiles/Engine.dir/build: Engine/libEngine.a
.PHONY : Engine/CMakeFiles/Engine.dir/build

Engine/CMakeFiles/Engine.dir/clean:
	cd /d C:\Users\hp\Desktop\code\MyGL\build_mingw\Engine && $(CMAKE_COMMAND) -P CMakeFiles\Engine.dir\cmake_clean.cmake
.PHONY : Engine/CMakeFiles/Engine.dir/clean

Engine/CMakeFiles/Engine.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\hp\Desktop\code\MyGL C:\Users\hp\Desktop\code\MyGL\Engine C:\Users\hp\Desktop\code\MyGL\build_mingw C:\Users\hp\Desktop\code\MyGL\build_mingw\Engine C:\Users\hp\Desktop\code\MyGL\build_mingw\Engine\CMakeFiles\Engine.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : Engine/CMakeFiles/Engine.dir/depend

