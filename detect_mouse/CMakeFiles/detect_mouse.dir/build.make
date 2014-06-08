# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/OpenCV_Samples/detect_mouse

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/OpenCV_Samples/detect_mouse

# Include any dependencies generated for this target.
include CMakeFiles/detect_mouse.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/detect_mouse.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/detect_mouse.dir/flags.make

CMakeFiles/detect_mouse.dir/main.o: CMakeFiles/detect_mouse.dir/flags.make
CMakeFiles/detect_mouse.dir/main.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/OpenCV_Samples/detect_mouse/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/detect_mouse.dir/main.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/detect_mouse.dir/main.o -c /root/OpenCV_Samples/detect_mouse/main.cpp

CMakeFiles/detect_mouse.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/detect_mouse.dir/main.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/OpenCV_Samples/detect_mouse/main.cpp > CMakeFiles/detect_mouse.dir/main.i

CMakeFiles/detect_mouse.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/detect_mouse.dir/main.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/OpenCV_Samples/detect_mouse/main.cpp -o CMakeFiles/detect_mouse.dir/main.s

CMakeFiles/detect_mouse.dir/main.o.requires:
.PHONY : CMakeFiles/detect_mouse.dir/main.o.requires

CMakeFiles/detect_mouse.dir/main.o.provides: CMakeFiles/detect_mouse.dir/main.o.requires
	$(MAKE) -f CMakeFiles/detect_mouse.dir/build.make CMakeFiles/detect_mouse.dir/main.o.provides.build
.PHONY : CMakeFiles/detect_mouse.dir/main.o.provides

CMakeFiles/detect_mouse.dir/main.o.provides.build: CMakeFiles/detect_mouse.dir/main.o

# Object files for target detect_mouse
detect_mouse_OBJECTS = \
"CMakeFiles/detect_mouse.dir/main.o"

# External object files for target detect_mouse
detect_mouse_EXTERNAL_OBJECTS =

detect_mouse: CMakeFiles/detect_mouse.dir/main.o
detect_mouse: /usr/local/lib/libopencv_videostab.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_video.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_ts.a
detect_mouse: /usr/local/lib/libopencv_superres.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_stitching.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_photo.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_ocl.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_objdetect.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_nonfree.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_ml.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_legacy.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_imgproc.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_highgui.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_gpu.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_flann.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_features2d.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_core.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_contrib.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_calib3d.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_nonfree.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_ocl.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_gpu.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_photo.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_objdetect.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_legacy.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_video.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_ml.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_calib3d.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_features2d.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_highgui.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_imgproc.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_flann.so.2.4.9
detect_mouse: /usr/local/lib/libopencv_core.so.2.4.9
detect_mouse: CMakeFiles/detect_mouse.dir/build.make
detect_mouse: CMakeFiles/detect_mouse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable detect_mouse"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/detect_mouse.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/detect_mouse.dir/build: detect_mouse
.PHONY : CMakeFiles/detect_mouse.dir/build

CMakeFiles/detect_mouse.dir/requires: CMakeFiles/detect_mouse.dir/main.o.requires
.PHONY : CMakeFiles/detect_mouse.dir/requires

CMakeFiles/detect_mouse.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/detect_mouse.dir/cmake_clean.cmake
.PHONY : CMakeFiles/detect_mouse.dir/clean

CMakeFiles/detect_mouse.dir/depend:
	cd /root/OpenCV_Samples/detect_mouse && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/OpenCV_Samples/detect_mouse /root/OpenCV_Samples/detect_mouse /root/OpenCV_Samples/detect_mouse /root/OpenCV_Samples/detect_mouse /root/OpenCV_Samples/detect_mouse/CMakeFiles/detect_mouse.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/detect_mouse.dir/depend
