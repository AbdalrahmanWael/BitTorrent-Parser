# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/golden/Programming/BitTorrent-Protocol

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/golden/Programming/BitTorrent-Protocol/build

# Include any dependencies generated for this target.
include CMakeFiles/bittorrent.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/bittorrent.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/bittorrent.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bittorrent.dir/flags.make

CMakeFiles/bittorrent.dir/src/main.c.o: CMakeFiles/bittorrent.dir/flags.make
CMakeFiles/bittorrent.dir/src/main.c.o: /home/golden/Programming/BitTorrent-Protocol/src/main.c
CMakeFiles/bittorrent.dir/src/main.c.o: CMakeFiles/bittorrent.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/golden/Programming/BitTorrent-Protocol/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bittorrent.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/bittorrent.dir/src/main.c.o -MF CMakeFiles/bittorrent.dir/src/main.c.o.d -o CMakeFiles/bittorrent.dir/src/main.c.o -c /home/golden/Programming/BitTorrent-Protocol/src/main.c

CMakeFiles/bittorrent.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/bittorrent.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/golden/Programming/BitTorrent-Protocol/src/main.c > CMakeFiles/bittorrent.dir/src/main.c.i

CMakeFiles/bittorrent.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/bittorrent.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/golden/Programming/BitTorrent-Protocol/src/main.c -o CMakeFiles/bittorrent.dir/src/main.c.s

CMakeFiles/bittorrent.dir/src/peer.c.o: CMakeFiles/bittorrent.dir/flags.make
CMakeFiles/bittorrent.dir/src/peer.c.o: /home/golden/Programming/BitTorrent-Protocol/src/peer.c
CMakeFiles/bittorrent.dir/src/peer.c.o: CMakeFiles/bittorrent.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/golden/Programming/BitTorrent-Protocol/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/bittorrent.dir/src/peer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/bittorrent.dir/src/peer.c.o -MF CMakeFiles/bittorrent.dir/src/peer.c.o.d -o CMakeFiles/bittorrent.dir/src/peer.c.o -c /home/golden/Programming/BitTorrent-Protocol/src/peer.c

CMakeFiles/bittorrent.dir/src/peer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/bittorrent.dir/src/peer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/golden/Programming/BitTorrent-Protocol/src/peer.c > CMakeFiles/bittorrent.dir/src/peer.c.i

CMakeFiles/bittorrent.dir/src/peer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/bittorrent.dir/src/peer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/golden/Programming/BitTorrent-Protocol/src/peer.c -o CMakeFiles/bittorrent.dir/src/peer.c.s

CMakeFiles/bittorrent.dir/src/torrent.c.o: CMakeFiles/bittorrent.dir/flags.make
CMakeFiles/bittorrent.dir/src/torrent.c.o: /home/golden/Programming/BitTorrent-Protocol/src/torrent.c
CMakeFiles/bittorrent.dir/src/torrent.c.o: CMakeFiles/bittorrent.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/golden/Programming/BitTorrent-Protocol/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/bittorrent.dir/src/torrent.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/bittorrent.dir/src/torrent.c.o -MF CMakeFiles/bittorrent.dir/src/torrent.c.o.d -o CMakeFiles/bittorrent.dir/src/torrent.c.o -c /home/golden/Programming/BitTorrent-Protocol/src/torrent.c

CMakeFiles/bittorrent.dir/src/torrent.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/bittorrent.dir/src/torrent.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/golden/Programming/BitTorrent-Protocol/src/torrent.c > CMakeFiles/bittorrent.dir/src/torrent.c.i

CMakeFiles/bittorrent.dir/src/torrent.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/bittorrent.dir/src/torrent.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/golden/Programming/BitTorrent-Protocol/src/torrent.c -o CMakeFiles/bittorrent.dir/src/torrent.c.s

CMakeFiles/bittorrent.dir/src/utils.c.o: CMakeFiles/bittorrent.dir/flags.make
CMakeFiles/bittorrent.dir/src/utils.c.o: /home/golden/Programming/BitTorrent-Protocol/src/utils.c
CMakeFiles/bittorrent.dir/src/utils.c.o: CMakeFiles/bittorrent.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/golden/Programming/BitTorrent-Protocol/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/bittorrent.dir/src/utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/bittorrent.dir/src/utils.c.o -MF CMakeFiles/bittorrent.dir/src/utils.c.o.d -o CMakeFiles/bittorrent.dir/src/utils.c.o -c /home/golden/Programming/BitTorrent-Protocol/src/utils.c

CMakeFiles/bittorrent.dir/src/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/bittorrent.dir/src/utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/golden/Programming/BitTorrent-Protocol/src/utils.c > CMakeFiles/bittorrent.dir/src/utils.c.i

CMakeFiles/bittorrent.dir/src/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/bittorrent.dir/src/utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/golden/Programming/BitTorrent-Protocol/src/utils.c -o CMakeFiles/bittorrent.dir/src/utils.c.s

CMakeFiles/bittorrent.dir/src/bencode.c.o: CMakeFiles/bittorrent.dir/flags.make
CMakeFiles/bittorrent.dir/src/bencode.c.o: /home/golden/Programming/BitTorrent-Protocol/src/bencode.c
CMakeFiles/bittorrent.dir/src/bencode.c.o: CMakeFiles/bittorrent.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/golden/Programming/BitTorrent-Protocol/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/bittorrent.dir/src/bencode.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/bittorrent.dir/src/bencode.c.o -MF CMakeFiles/bittorrent.dir/src/bencode.c.o.d -o CMakeFiles/bittorrent.dir/src/bencode.c.o -c /home/golden/Programming/BitTorrent-Protocol/src/bencode.c

CMakeFiles/bittorrent.dir/src/bencode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/bittorrent.dir/src/bencode.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/golden/Programming/BitTorrent-Protocol/src/bencode.c > CMakeFiles/bittorrent.dir/src/bencode.c.i

CMakeFiles/bittorrent.dir/src/bencode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/bittorrent.dir/src/bencode.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/golden/Programming/BitTorrent-Protocol/src/bencode.c -o CMakeFiles/bittorrent.dir/src/bencode.c.s

CMakeFiles/bittorrent.dir/src/tracker.c.o: CMakeFiles/bittorrent.dir/flags.make
CMakeFiles/bittorrent.dir/src/tracker.c.o: /home/golden/Programming/BitTorrent-Protocol/src/tracker.c
CMakeFiles/bittorrent.dir/src/tracker.c.o: CMakeFiles/bittorrent.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/golden/Programming/BitTorrent-Protocol/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/bittorrent.dir/src/tracker.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/bittorrent.dir/src/tracker.c.o -MF CMakeFiles/bittorrent.dir/src/tracker.c.o.d -o CMakeFiles/bittorrent.dir/src/tracker.c.o -c /home/golden/Programming/BitTorrent-Protocol/src/tracker.c

CMakeFiles/bittorrent.dir/src/tracker.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/bittorrent.dir/src/tracker.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/golden/Programming/BitTorrent-Protocol/src/tracker.c > CMakeFiles/bittorrent.dir/src/tracker.c.i

CMakeFiles/bittorrent.dir/src/tracker.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/bittorrent.dir/src/tracker.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/golden/Programming/BitTorrent-Protocol/src/tracker.c -o CMakeFiles/bittorrent.dir/src/tracker.c.s

CMakeFiles/bittorrent.dir/src/piece.c.o: CMakeFiles/bittorrent.dir/flags.make
CMakeFiles/bittorrent.dir/src/piece.c.o: /home/golden/Programming/BitTorrent-Protocol/src/piece.c
CMakeFiles/bittorrent.dir/src/piece.c.o: CMakeFiles/bittorrent.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/golden/Programming/BitTorrent-Protocol/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/bittorrent.dir/src/piece.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/bittorrent.dir/src/piece.c.o -MF CMakeFiles/bittorrent.dir/src/piece.c.o.d -o CMakeFiles/bittorrent.dir/src/piece.c.o -c /home/golden/Programming/BitTorrent-Protocol/src/piece.c

CMakeFiles/bittorrent.dir/src/piece.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/bittorrent.dir/src/piece.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/golden/Programming/BitTorrent-Protocol/src/piece.c > CMakeFiles/bittorrent.dir/src/piece.c.i

CMakeFiles/bittorrent.dir/src/piece.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/bittorrent.dir/src/piece.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/golden/Programming/BitTorrent-Protocol/src/piece.c -o CMakeFiles/bittorrent.dir/src/piece.c.s

CMakeFiles/bittorrent.dir/src/network.c.o: CMakeFiles/bittorrent.dir/flags.make
CMakeFiles/bittorrent.dir/src/network.c.o: /home/golden/Programming/BitTorrent-Protocol/src/network.c
CMakeFiles/bittorrent.dir/src/network.c.o: CMakeFiles/bittorrent.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/golden/Programming/BitTorrent-Protocol/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/bittorrent.dir/src/network.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/bittorrent.dir/src/network.c.o -MF CMakeFiles/bittorrent.dir/src/network.c.o.d -o CMakeFiles/bittorrent.dir/src/network.c.o -c /home/golden/Programming/BitTorrent-Protocol/src/network.c

CMakeFiles/bittorrent.dir/src/network.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/bittorrent.dir/src/network.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/golden/Programming/BitTorrent-Protocol/src/network.c > CMakeFiles/bittorrent.dir/src/network.c.i

CMakeFiles/bittorrent.dir/src/network.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/bittorrent.dir/src/network.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/golden/Programming/BitTorrent-Protocol/src/network.c -o CMakeFiles/bittorrent.dir/src/network.c.s

CMakeFiles/bittorrent.dir/src/config.c.o: CMakeFiles/bittorrent.dir/flags.make
CMakeFiles/bittorrent.dir/src/config.c.o: /home/golden/Programming/BitTorrent-Protocol/src/config.c
CMakeFiles/bittorrent.dir/src/config.c.o: CMakeFiles/bittorrent.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/golden/Programming/BitTorrent-Protocol/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/bittorrent.dir/src/config.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/bittorrent.dir/src/config.c.o -MF CMakeFiles/bittorrent.dir/src/config.c.o.d -o CMakeFiles/bittorrent.dir/src/config.c.o -c /home/golden/Programming/BitTorrent-Protocol/src/config.c

CMakeFiles/bittorrent.dir/src/config.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/bittorrent.dir/src/config.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/golden/Programming/BitTorrent-Protocol/src/config.c > CMakeFiles/bittorrent.dir/src/config.c.i

CMakeFiles/bittorrent.dir/src/config.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/bittorrent.dir/src/config.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/golden/Programming/BitTorrent-Protocol/src/config.c -o CMakeFiles/bittorrent.dir/src/config.c.s

# Object files for target bittorrent
bittorrent_OBJECTS = \
"CMakeFiles/bittorrent.dir/src/main.c.o" \
"CMakeFiles/bittorrent.dir/src/peer.c.o" \
"CMakeFiles/bittorrent.dir/src/torrent.c.o" \
"CMakeFiles/bittorrent.dir/src/utils.c.o" \
"CMakeFiles/bittorrent.dir/src/bencode.c.o" \
"CMakeFiles/bittorrent.dir/src/tracker.c.o" \
"CMakeFiles/bittorrent.dir/src/piece.c.o" \
"CMakeFiles/bittorrent.dir/src/network.c.o" \
"CMakeFiles/bittorrent.dir/src/config.c.o"

# External object files for target bittorrent
bittorrent_EXTERNAL_OBJECTS =

bittorrent: CMakeFiles/bittorrent.dir/src/main.c.o
bittorrent: CMakeFiles/bittorrent.dir/src/peer.c.o
bittorrent: CMakeFiles/bittorrent.dir/src/torrent.c.o
bittorrent: CMakeFiles/bittorrent.dir/src/utils.c.o
bittorrent: CMakeFiles/bittorrent.dir/src/bencode.c.o
bittorrent: CMakeFiles/bittorrent.dir/src/tracker.c.o
bittorrent: CMakeFiles/bittorrent.dir/src/piece.c.o
bittorrent: CMakeFiles/bittorrent.dir/src/network.c.o
bittorrent: CMakeFiles/bittorrent.dir/src/config.c.o
bittorrent: CMakeFiles/bittorrent.dir/build.make
bittorrent: /usr/lib/libcurl.so
bittorrent: /usr/lib/libssl.so
bittorrent: /usr/lib/libcrypto.so
bittorrent: CMakeFiles/bittorrent.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/golden/Programming/BitTorrent-Protocol/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable bittorrent"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bittorrent.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bittorrent.dir/build: bittorrent
.PHONY : CMakeFiles/bittorrent.dir/build

CMakeFiles/bittorrent.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bittorrent.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bittorrent.dir/clean

CMakeFiles/bittorrent.dir/depend:
	cd /home/golden/Programming/BitTorrent-Protocol/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/golden/Programming/BitTorrent-Protocol /home/golden/Programming/BitTorrent-Protocol /home/golden/Programming/BitTorrent-Protocol/build /home/golden/Programming/BitTorrent-Protocol/build /home/golden/Programming/BitTorrent-Protocol/build/CMakeFiles/bittorrent.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/bittorrent.dir/depend

