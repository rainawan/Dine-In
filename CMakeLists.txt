cmake_minimum_required(VERSION 3.14)
project(DineIn)

set(CMAKE_CXX_FLAGS " -std=c++11")

# Find's all the source files within a project and groups them within the (PROJECTNAME)_SRC file.
file(GLOB DineIn_SRC CONFIGURE_DEPENDS "*.h" "*.cpp")

set(SOURCE_FILES main.cpp)

# Add's all the found source files within the executable
add_executable(DineIn ${DineIn_SRC} SFMLTools/Application.cpp SFMLTools/Application.h SFMLTools/GUIComponent.cpp SFMLTools/GUIComponent.h SFMLTools/States.cpp SFMLTools/States.h)
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories()
target_link_libraries(DineIn sfml-system sfml-window sfml-graphics sfml-audio sfml-network)