cmake_minimum_required(VERSION 3.10)
project(bittorrent_project C)

# Set the C standard to C11
set(CMAKE_C_STANDARD 11)

# Add your source files
add_executable(bittorrent
    src/main.c
    src/peer.c
    src/torrent.c
    src/utils.c
    src/bencode.c
)

# Include directories
target_include_directories(bittorrent PRIVATE include)

# Compiler options
target_compile_options(bittorrent PRIVATE -Wall -Wextra)

# Optional: Link against any external libraries if needed
# target_link_libraries(bittorrent PUBLIC your_library_name)

# Optional: Set additional project-specific configurations
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DYOUR_MACRO")

