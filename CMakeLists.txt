
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
    src/tracker.c
    src/piece.c
    src/network.c
    src/config.c
)

# Include directories
target_include_directories(bittorrent PRIVATE include)

# Compiler options
target_compile_options(bittorrent PRIVATE -Wall -Wextra)

# Find and include libcurl
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

# Link your executable against libcurl
target_link_libraries(bittorrent ${CURL_LIBRARIES})

# Find and include OpenSSL
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

# Link your executable against OpenSSL
target_link_libraries(bittorrent ${OPENSSL_LIBRARIES})

# Optional: Set additional project-specific configurations
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DYOUR_MACRO")


