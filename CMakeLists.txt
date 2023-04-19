cmake_minimum_required(VERSION 3.14)
project(DineIn)

set(CMAKE_CXX_FLAGS " -std=c++11")

# Find's all the source files within a project and groups them within the (PROJECTNAME)_SRC file.
file(GLOB DineIn_SRC CONFIGURE_DEPENDS "*.h" "*.cpp")

set(SOURCE_FILES main.cpp)

# Add's all the found source files within the executable
add_executable(DineIn ${DineIn_SRC}
        Applications/HomePage.cpp Applications/HomePage.h
        Components/FileTree/FileTree.cpp Components/FileTree/FileTree.h Components/FileTree/FileTreeNode.cpp Components/FileTree/FileTreeNode.h
        Components/History/DropdownSnapshot.cpp Components/History/DropdownSnapshot.h Components/History/History.cpp Components/History/History.h Components/History/Snapshot.cpp Components/History/Snapshot.h Components/History/SnapshotInterface.cpp Components/History/SnapshotInterface.h Components/History/TextInputSnapshot.cpp Components/History/TextInputSnapshot.h
        Components/Menu/DropdownMenu.cpp Components/Menu/DropdownMenu.h Components/Menu/Item.cpp Components/Menu/Item.h Components/Menu/ItemList.cpp Components/Menu/ItemList.h Components/Menu/MenuBar.cpp Components/Menu/MenuBar.h
        Components/TextInput/Cursor.cpp Components/TextInput/Cursor.h Components/TextInput/TextBox.cpp Components/TextInput/TextBox.h Components/TextInput/TextInput.cpp Components/TextInput/TextInput.h Components/TextInput/Typing.cpp Components/TextInput/Typing.h Applications/HomePage.cpp Applications/HomePage.h
        SFMLTools/Application.cpp SFMLTools/Application.h SFMLTools/Fonts.cpp SFMLTools/Fonts.h SFMLTools/GUIComponent.cpp SFMLTools/GUIComponent.h SFMLTools/Image.cpp SFMLTools/Image.h SFMLTools/MouseEvents.cpp SFMLTools/MouseEvents.h SFMLTools/Position.cpp SFMLTools/Position.h SFMLTools/Sprites.cpp SFMLTools/Sprites.h SFMLTools/States.cpp SFMLTools/States.h)
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories()
target_link_libraries(DineIn sfml-system sfml-window sfml-graphics sfml-audio sfml-network)