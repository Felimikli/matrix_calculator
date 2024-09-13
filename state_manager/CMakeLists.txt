
# Define the source files for matrix_history
file(GLOB_RECURSE HIST_SRC_FILES "src/*.c")

# Create a static library for matrix_history
add_library(state_manager STATIC ${HIST_SRC_FILES})

# Optionally set include directories if needed
target_include_directories(state_manager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
