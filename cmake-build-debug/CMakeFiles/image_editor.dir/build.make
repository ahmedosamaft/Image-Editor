# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\projects\Image-Editor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\projects\Image-Editor\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/image_editor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/image_editor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/image_editor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/image_editor.dir/flags.make

CMakeFiles/image_editor.dir/main.cpp.obj: CMakeFiles/image_editor.dir/flags.make
CMakeFiles/image_editor.dir/main.cpp.obj: C:/projects/Image-Editor/main.cpp
CMakeFiles/image_editor.dir/main.cpp.obj: CMakeFiles/image_editor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\projects\Image-Editor\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/image_editor.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image_editor.dir/main.cpp.obj -MF CMakeFiles\image_editor.dir\main.cpp.obj.d -o CMakeFiles\image_editor.dir\main.cpp.obj -c C:\projects\Image-Editor\main.cpp

CMakeFiles/image_editor.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_editor.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\projects\Image-Editor\main.cpp > CMakeFiles\image_editor.dir\main.cpp.i

CMakeFiles/image_editor.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_editor.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\projects\Image-Editor\main.cpp -o CMakeFiles\image_editor.dir\main.cpp.s

CMakeFiles/image_editor.dir/dependency/Reader.cpp.obj: CMakeFiles/image_editor.dir/flags.make
CMakeFiles/image_editor.dir/dependency/Reader.cpp.obj: C:/projects/Image-Editor/dependency/Reader.cpp
CMakeFiles/image_editor.dir/dependency/Reader.cpp.obj: CMakeFiles/image_editor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\projects\Image-Editor\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/image_editor.dir/dependency/Reader.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image_editor.dir/dependency/Reader.cpp.obj -MF CMakeFiles\image_editor.dir\dependency\Reader.cpp.obj.d -o CMakeFiles\image_editor.dir\dependency\Reader.cpp.obj -c C:\projects\Image-Editor\dependency\Reader.cpp

CMakeFiles/image_editor.dir/dependency/Reader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_editor.dir/dependency/Reader.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\projects\Image-Editor\dependency\Reader.cpp > CMakeFiles\image_editor.dir\dependency\Reader.cpp.i

CMakeFiles/image_editor.dir/dependency/Reader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_editor.dir/dependency/Reader.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\projects\Image-Editor\dependency\Reader.cpp -o CMakeFiles\image_editor.dir\dependency\Reader.cpp.s

CMakeFiles/image_editor.dir/dependency/bmplib.cpp.obj: CMakeFiles/image_editor.dir/flags.make
CMakeFiles/image_editor.dir/dependency/bmplib.cpp.obj: C:/projects/Image-Editor/dependency/bmplib.cpp
CMakeFiles/image_editor.dir/dependency/bmplib.cpp.obj: CMakeFiles/image_editor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\projects\Image-Editor\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/image_editor.dir/dependency/bmplib.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image_editor.dir/dependency/bmplib.cpp.obj -MF CMakeFiles\image_editor.dir\dependency\bmplib.cpp.obj.d -o CMakeFiles\image_editor.dir\dependency\bmplib.cpp.obj -c C:\projects\Image-Editor\dependency\bmplib.cpp

CMakeFiles/image_editor.dir/dependency/bmplib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_editor.dir/dependency/bmplib.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\projects\Image-Editor\dependency\bmplib.cpp > CMakeFiles\image_editor.dir\dependency\bmplib.cpp.i

CMakeFiles/image_editor.dir/dependency/bmplib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_editor.dir/dependency/bmplib.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\projects\Image-Editor\dependency\bmplib.cpp -o CMakeFiles\image_editor.dir\dependency\bmplib.cpp.s

CMakeFiles/image_editor.dir/classes/View.cpp.obj: CMakeFiles/image_editor.dir/flags.make
CMakeFiles/image_editor.dir/classes/View.cpp.obj: C:/projects/Image-Editor/classes/View.cpp
CMakeFiles/image_editor.dir/classes/View.cpp.obj: CMakeFiles/image_editor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\projects\Image-Editor\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/image_editor.dir/classes/View.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image_editor.dir/classes/View.cpp.obj -MF CMakeFiles\image_editor.dir\classes\View.cpp.obj.d -o CMakeFiles\image_editor.dir\classes\View.cpp.obj -c C:\projects\Image-Editor\classes\View.cpp

CMakeFiles/image_editor.dir/classes/View.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_editor.dir/classes/View.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\projects\Image-Editor\classes\View.cpp > CMakeFiles\image_editor.dir\classes\View.cpp.i

CMakeFiles/image_editor.dir/classes/View.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_editor.dir/classes/View.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\projects\Image-Editor\classes\View.cpp -o CMakeFiles\image_editor.dir\classes\View.cpp.s

CMakeFiles/image_editor.dir/classes/Helper.cpp.obj: CMakeFiles/image_editor.dir/flags.make
CMakeFiles/image_editor.dir/classes/Helper.cpp.obj: C:/projects/Image-Editor/classes/Helper.cpp
CMakeFiles/image_editor.dir/classes/Helper.cpp.obj: CMakeFiles/image_editor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\projects\Image-Editor\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/image_editor.dir/classes/Helper.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image_editor.dir/classes/Helper.cpp.obj -MF CMakeFiles\image_editor.dir\classes\Helper.cpp.obj.d -o CMakeFiles\image_editor.dir\classes\Helper.cpp.obj -c C:\projects\Image-Editor\classes\Helper.cpp

CMakeFiles/image_editor.dir/classes/Helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_editor.dir/classes/Helper.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\projects\Image-Editor\classes\Helper.cpp > CMakeFiles\image_editor.dir\classes\Helper.cpp.i

CMakeFiles/image_editor.dir/classes/Helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_editor.dir/classes/Helper.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\projects\Image-Editor\classes\Helper.cpp -o CMakeFiles\image_editor.dir\classes\Helper.cpp.s

CMakeFiles/image_editor.dir/classes/Filter.cpp.obj: CMakeFiles/image_editor.dir/flags.make
CMakeFiles/image_editor.dir/classes/Filter.cpp.obj: C:/projects/Image-Editor/classes/Filter.cpp
CMakeFiles/image_editor.dir/classes/Filter.cpp.obj: CMakeFiles/image_editor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\projects\Image-Editor\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/image_editor.dir/classes/Filter.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image_editor.dir/classes/Filter.cpp.obj -MF CMakeFiles\image_editor.dir\classes\Filter.cpp.obj.d -o CMakeFiles\image_editor.dir\classes\Filter.cpp.obj -c C:\projects\Image-Editor\classes\Filter.cpp

CMakeFiles/image_editor.dir/classes/Filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_editor.dir/classes/Filter.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\projects\Image-Editor\classes\Filter.cpp > CMakeFiles\image_editor.dir\classes\Filter.cpp.i

CMakeFiles/image_editor.dir/classes/Filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_editor.dir/classes/Filter.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\projects\Image-Editor\classes\Filter.cpp -o CMakeFiles\image_editor.dir\classes\Filter.cpp.s

# Object files for target image_editor
image_editor_OBJECTS = \
"CMakeFiles/image_editor.dir/main.cpp.obj" \
"CMakeFiles/image_editor.dir/dependency/Reader.cpp.obj" \
"CMakeFiles/image_editor.dir/dependency/bmplib.cpp.obj" \
"CMakeFiles/image_editor.dir/classes/View.cpp.obj" \
"CMakeFiles/image_editor.dir/classes/Helper.cpp.obj" \
"CMakeFiles/image_editor.dir/classes/Filter.cpp.obj"

# External object files for target image_editor
image_editor_EXTERNAL_OBJECTS =

image_editor.exe: CMakeFiles/image_editor.dir/main.cpp.obj
image_editor.exe: CMakeFiles/image_editor.dir/dependency/Reader.cpp.obj
image_editor.exe: CMakeFiles/image_editor.dir/dependency/bmplib.cpp.obj
image_editor.exe: CMakeFiles/image_editor.dir/classes/View.cpp.obj
image_editor.exe: CMakeFiles/image_editor.dir/classes/Helper.cpp.obj
image_editor.exe: CMakeFiles/image_editor.dir/classes/Filter.cpp.obj
image_editor.exe: CMakeFiles/image_editor.dir/build.make
image_editor.exe: CMakeFiles/image_editor.dir/linkLibs.rsp
image_editor.exe: CMakeFiles/image_editor.dir/objects1
image_editor.exe: CMakeFiles/image_editor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\projects\Image-Editor\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable image_editor.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\image_editor.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/image_editor.dir/build: image_editor.exe
.PHONY : CMakeFiles/image_editor.dir/build

CMakeFiles/image_editor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\image_editor.dir\cmake_clean.cmake
.PHONY : CMakeFiles/image_editor.dir/clean

CMakeFiles/image_editor.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\projects\Image-Editor C:\projects\Image-Editor C:\projects\Image-Editor\cmake-build-debug C:\projects\Image-Editor\cmake-build-debug C:\projects\Image-Editor\cmake-build-debug\CMakeFiles\image_editor.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/image_editor.dir/depend
