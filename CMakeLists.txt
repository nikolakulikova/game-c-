set(CMAKE_CXX_STANDARD 14)
cmake_minimum_required(VERSION 3.6.2)
project(projekt)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads)

set(SOURCE_FILES
        objects/Unit.cpp
        objects/Player.cpp
        objects/Monster.cpp
        objects/Item.cpp
        objects/MapObject.cpp
        objects/Wall.cpp
        gui/Gui.cpp
        map/Map.cpp
#        tests/test_objects.cpp
        tests/test_map.cpp
        tests/test_item.cpp
        tests/test_monster.cpp
        tests/test_player.cpp
        tests/test_wall.cpp


        GoogleTest/gtest-death-test.cc
        GoogleTest/gtest-filepath.cc
        GoogleTest/gtest-port.cc
        GoogleTest/gtest-printers.cc
        GoogleTest/gtest-test-part.cc
        GoogleTest/gtest-typed-test.cc
        GoogleTest/gtest.cc
        GoogleTest/gtest_main.cc)

include_directories(GoogleTest)
add_executable(projekt ${SOURCE_FILES})
target_link_libraries(projekt ${CMAKE_THREAD_LIBS_INIT})
#add_executable(projekt main.cpp)