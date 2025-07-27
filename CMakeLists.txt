cmake_minimum_required(VERSION 4.0)
project(corelib VERSION 0.1.0 LANGUAGES CXX)

# Use C++26 via c++2c
# set(CMAKE_CXX_STANDARD 26)  # Uncomment this in March 2026, when C++26 is officially released
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-std=c++2c)  # Remove this line when C++26 is officially released

# Create the library target (header-only)
add_library(corelib INTERFACE)
target_include_directories(corelib INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Test executable with multiple source files
add_executable(test_corelib
    tests/corelib/test_main.cpp
    tests/corelib/test_math.cpp
)
target_link_libraries(test_corelib PRIVATE corelib)
target_include_directories(test_corelib PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/external
)

# Add test target
enable_testing()
add_test(NAME TestCoreLib COMMAND test_corelib)

# Custom target to run tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --verbose
    DEPENDS test_corelib
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
