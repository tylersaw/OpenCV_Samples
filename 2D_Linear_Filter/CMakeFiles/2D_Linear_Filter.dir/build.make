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
CMAKE_SOURCE_DIR = /root/OpenCV_Samples/2D_Linear_Filter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/OpenCV_Samples/2D_Linear_Filter

# Include any dependencies generated for this target.
include CMakeFiles/2D_Linear_Filter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2D_Linear_Filter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2D_Linear_Filter.dir/flags.make

CMakeFiles/2D_Linear_Filter.dir/main.o: CMakeFiles/2D_Linear_Filter.dir/flags.make
CMakeFiles/2D_Linear_Filter.dir/main.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/OpenCV_Samples/2D_Linear_Filter/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/2D_Linear_Filter.dir/main.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/2D_Linear_Filter.dir/main.o -c /root/OpenCV_Samples/2D_Linear_Filter/main.cpp

CMakeFiles/2D_Linear_Filter.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2D_Linear_Filter.dir/main.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/OpenCV_Samples/2D_Linear_Filter/main.cpp > CMakeFiles/2D_Linear_Filter.dir/main.i

CMakeFiles/2D_Linear_Filter.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2D_Linear_Filter.dir/main.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/OpenCV_Samples/2D_Linear_Filter/main.cpp -o CMakeFiles/2D_Linear_Filter.dir/main.s

CMakeFiles/2D_Linear_Filter.dir/main.o.requires:
.PHONY : CMakeFiles/2D_Linear_Filter.dir/main.o.requires

CMakeFiles/2D_Linear_Filter.dir/main.o.provides: CMakeFiles/2D_Linear_Filter.dir/main.o.requires
	$(MAKE) -f CMakeFiles/2D_Linear_Filter.dir/build.make CMakeFiles/2D_Linear_Filter.dir/main.o.provides.build
.PHONY : CMakeFiles/2D_Linear_Filter.dir/main.o.provides

CMakeFiles/2D_Linear_Filter.dir/main.o.provides.build: CMakeFiles/2D_Linear_Filter.dir/main.o

# Object files for target 2D_Linear_Filter
2D_Linear_Filter_OBJECTS = \
"CMakeFiles/2D_Linear_Filter.dir/main.o"

# External object files for target 2D_Linear_Filter
2D_Linear_Filter_EXTERNAL_OBJECTS =

2D_Linear_Filter: CMakeFiles/2D_Linear_Filter.dir/main.o
2D_Linear_Filter: /usr/local/lib/libopencv_videostab.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_video.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_ts.a
2D_Linear_Filter: /usr/local/lib/libopencv_superres.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_stitching.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_photo.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_ocl.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_objdetect.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_nonfree.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_ml.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_legacy.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_imgproc.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_highgui.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_gpu.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_flann.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_features2d.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_core.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_contrib.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_calib3d.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_nonfree.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_ocl.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_gpu.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_photo.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_objdetect.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_legacy.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_video.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_ml.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_calib3d.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_features2d.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_highgui.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_imgproc.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_flann.so.2.4.9
2D_Linear_Filter: /usr/local/lib/libopencv_core.so.2.4.9
2D_Linear_Filter: CMakeFiles/2D_Linear_Filter.dir/build.make
2D_Linear_Filter: CMakeFiles/2D_Linear_Filter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable 2D_Linear_Filter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2D_Linear_Filter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2D_Linear_Filter.dir/build: 2D_Linear_Filter
.PHONY : CMakeFiles/2D_Linear_Filter.dir/build

CMakeFiles/2D_Linear_Filter.dir/requires: CMakeFiles/2D_Linear_Filter.dir/main.o.requires
.PHONY : CMakeFiles/2D_Linear_Filter.dir/requires

CMakeFiles/2D_Linear_Filter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2D_Linear_Filter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2D_Linear_Filter.dir/clean

CMakeFiles/2D_Linear_Filter.dir/depend:
	cd /root/OpenCV_Samples/2D_Linear_Filter && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/OpenCV_Samples/2D_Linear_Filter /root/OpenCV_Samples/2D_Linear_Filter /root/OpenCV_Samples/2D_Linear_Filter /root/OpenCV_Samples/2D_Linear_Filter /root/OpenCV_Samples/2D_Linear_Filter/CMakeFiles/2D_Linear_Filter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2D_Linear_Filter.dir/depend

