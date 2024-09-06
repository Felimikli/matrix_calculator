# Define the source files for operations
file(GLOB_RECURSE OPS_SRC_FILES "src/*.c")

# Create a static library for operations
add_library(operations STATIC ${OPS_SRC_FILES})

# Optionally set include directories if needed
target_include_directories(operations PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
