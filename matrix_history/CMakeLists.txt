
# Define the source files for matrix_history
file(GLOB_RECURSE HIST_SRC_FILES "src/*.c")

# Create a static library for matrix_history
add_library(history_management STATIC ${HIST_SRC_FILES})

# Optionally set include directories if needed
target_include_directories(history_management PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
