
# Define the source files for UI
file(GLOB_RECURSE UI_SRC_FILES "src/*.cpp")

# Create a static library for UI
add_library(ui STATIC ${UI_SRC_FILES})

# Optionally set include directories if needed
target_include_directories(ui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
