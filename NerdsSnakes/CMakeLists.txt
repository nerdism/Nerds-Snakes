# CMakeList.txt : CMake project for Pong, include source and define
# project specific logic here.
#

find_package(SFML COMPONENTS system window graphics network audio)

set(TGUI_STATIC_LIBRARIES TRUE)
find_package(TGUI CONFIG REQUIRED)



# Add source to this project's executable.
add_executable (NerdsSnakes WIN32 "main.cpp" "game/Game.cpp" "game/MainMenuState.cpp")

set(LIBS sfml-graphics sfml-audio sfml-system sfml-network sfml-window tgui)

if (CMAKE_HOST_WIN32)
  list(APPEND LIBS sfml-main)
endif()

target_link_libraries(NerdsSnakes PRIVATE ${LIBS})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET NerdsSnakes PROPERTY CXX_STANDARD 20)
endif()


# TODO: Add tests and install targets if needed.
