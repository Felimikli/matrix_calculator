set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
cmake_minimum_required(VERSION 3.10)
project(MatrixCalc)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/operations/include
    ${CMAKE_CURRENT_SOURCE_DIR}/matrix_history/include
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/include
)

# Add subdirectories
add_subdirectory(operations)
add_subdirectory(matrix_history)
add_subdirectory(ui)

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

