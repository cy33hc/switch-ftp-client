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
CMAKE_SOURCE_DIR = /home/cyee/projects/switch-ftp-client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cyee/projects/switch-ftp-client/build

# Utility rule file for imgui_vsh_install_to_switch-ftp-client_romfs.

# Include the progress variables for this target.
include CMakeFiles/imgui_vsh_install_to_switch-ftp-client_romfs.dir/progress.make

CMakeFiles/imgui_vsh_install_to_switch-ftp-client_romfs: romfs/shaders/imgui_vsh.dksh


romfs/shaders/imgui_vsh.dksh: imgui_vsh.dksh
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/cyee/projects/switch-ftp-client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Installing imgui_vsh to switch-ftp-client_romfs"
	/usr/bin/cmake -E make_directory /home/cyee/projects/switch-ftp-client/build/romfs/shaders
	/usr/bin/cmake -E copy /home/cyee/projects/switch-ftp-client/build/imgui_vsh.dksh /home/cyee/projects/switch-ftp-client/build/romfs/shaders/imgui_vsh.dksh

imgui_vsh.dksh: ../src/imgui_vsh.glsl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/cyee/projects/switch-ftp-client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building shader program imgui_vsh"
	/opt/devkitpro/tools/bin/uam -o /home/cyee/projects/switch-ftp-client/build/imgui_vsh.dksh -s vert /home/cyee/projects/switch-ftp-client/src/imgui_vsh.glsl

imgui_vsh_install_to_switch-ftp-client_romfs: CMakeFiles/imgui_vsh_install_to_switch-ftp-client_romfs
imgui_vsh_install_to_switch-ftp-client_romfs: romfs/shaders/imgui_vsh.dksh
imgui_vsh_install_to_switch-ftp-client_romfs: imgui_vsh.dksh
imgui_vsh_install_to_switch-ftp-client_romfs: CMakeFiles/imgui_vsh_install_to_switch-ftp-client_romfs.dir/build.make

.PHONY : imgui_vsh_install_to_switch-ftp-client_romfs

# Rule to build all files generated by this target.
CMakeFiles/imgui_vsh_install_to_switch-ftp-client_romfs.dir/build: imgui_vsh_install_to_switch-ftp-client_romfs

.PHONY : CMakeFiles/imgui_vsh_install_to_switch-ftp-client_romfs.dir/build

CMakeFiles/imgui_vsh_install_to_switch-ftp-client_romfs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/imgui_vsh_install_to_switch-ftp-client_romfs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/imgui_vsh_install_to_switch-ftp-client_romfs.dir/clean

CMakeFiles/imgui_vsh_install_to_switch-ftp-client_romfs.dir/depend:
	cd /home/cyee/projects/switch-ftp-client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cyee/projects/switch-ftp-client /home/cyee/projects/switch-ftp-client /home/cyee/projects/switch-ftp-client/build /home/cyee/projects/switch-ftp-client/build /home/cyee/projects/switch-ftp-client/build/CMakeFiles/imgui_vsh_install_to_switch-ftp-client_romfs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/imgui_vsh_install_to_switch-ftp-client_romfs.dir/depend
