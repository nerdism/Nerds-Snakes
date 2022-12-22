# CMakeList.txt : CMake project for Pong, include source and define
# project specific logic here.
#

find_package(SFML COMPONENTS system window graphics network audio)

set(TGUI_STATIC_LIBRARIES TRUE)
find_package(TGUI CONFIG REQUIRED)



# Add source to this project's executable.
add_executable (NerdsSnakes "main.cpp" "game/game.cpp")

target_link_libraries(NerdsSnakes PRIVATE sfml-graphics sfml-audio sfml-system sfml-network sfml-main sfml-window)
target_link_libraries(NerdsSnakes PRIVATE tgui)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET NerdsSnakes PROPERTY CXX_STANDARD 20)
endif()


# TODO: Add tests and install targets if needed.
