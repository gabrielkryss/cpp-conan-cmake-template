cmake_minimum_required(VERSION 3.30)
project(MyProject LANGUAGES CXX)

# Enable C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# setting toolchain file here doesn't seem to work but doing it in commmand line -DCMAKE_TOOLCHAIN_FILE works?
# set(CMAKE_TOOLCHAIN_FILE "${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake")

message("CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message("CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")
message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message("CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
message("CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")

# Find packages
# find_package(Vulkan REQUIRED)
find_package(spdlog REQUIRED)
find_package(EnTT REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)

# Add source files
add_executable(${PROJECT_NAME} 
  src/main.cpp
  src/MyClass.cpp
)

# Add header and interface files
target_sources(${PROJECT_NAME} PRIVATE
  include/MyClass.ixx
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE 
  # Vulkan::Vulkan
  spdlog::spdlog
  EnTT::EnTT
  glfw 
  glm
)

# Add examples
# add_subdirectory(examples/example1)
# add_subdirectory(examples/example2)
