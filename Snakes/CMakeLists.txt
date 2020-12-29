# CMakeList.txt : CMake project for Snakes, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Snakes "main.cpp" "snake.cpp" "board.cpp")


if (CMAKE_HOST_UNIX) 

    target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${PNG_LIBRARY})
    target_link_libraries(${PROJECT_NAME} PRIVATE X11)

endif (CMAKE_HOST_UNIX)

target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

# TODO: Add tests and install targets if needed.
