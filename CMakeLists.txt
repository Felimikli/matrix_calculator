cmake_minimum_required(VERSION 3.10)
project(MatrixCalc)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories
add_subdirectory(operations)
add_subdirectory(matrix_history)
add_subdirectory(ui)

# Define include directories
include_directories(
    operations/include
    matrix_history/include
    ui/include
)

# Add the executable target
add_executable(matrix_calc
    src/main.c
)

# Link libraries
target_link_libraries(matrix_calc
    operations
    history_management
    ui
)

