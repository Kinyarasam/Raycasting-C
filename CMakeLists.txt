cmake_minimum_required(VERSION 3.0)
project(raycasting C)

# Compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lm -Wall -Werror -Wextra -pedantic -std=c11")

# Directories
set(SRC_DIR src)
set(BUILD_DIR build)
set(BIN_DIR bin)

# Find SDL2 package
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} include)

# Source files
file(GLOB SRC_FILES ${SRC_DIR}/*.c)

# Output executable
add_executable(raycasting ${SRC_FILES})

# Link SDL2 libraries
target_link_libraries(raycasting ${SDL2_LIBRARIES} m)

# Output directory
set_target_properties(raycasting PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}"
    ARCHIVE_OUTPUT_DIRECTORY "${BUILD_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${BUILD_DIR}"
)

# Copy assets directory to the output directory
add_custom_command(TARGET raycasting POST_BUILD
    COMMAND $(CMAKE_COMMAND) -E copy_directory
    $(CMAKE_SOURCE_DIR)/assets $<TARGET_FILE_DIR:raycasting>/assets
)

# Clean target
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/cmake/clean-all.cmake
)
