cmake_minimum_required(VERSION 3.15)
project(cpp-actions-test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set vcpkg toolchain file if not already set
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
  else()
    # For submodule usage
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
  endif()
endif()

# Find required packages
find_package(fmt CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

# Main application
add_executable(main_app main.cpp utils.cpp)
target_link_libraries(main_app PRIVATE fmt::fmt-header-only)

# Test executable
add_executable(run_tests tests.cpp utils.cpp)
target_link_libraries(run_tests PRIVATE GTest::gtest GTest::gtest_main fmt::fmt)

# Enable testing
enable_testing()
add_test(NAME UtilsTests COMMAND run_tests)
