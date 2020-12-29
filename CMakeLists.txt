# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

set (CMAKE_CXX_STANDARD 17)

project ("Snakes")

if (CMAKE_HOST_UNIX )
    set(THREADS_PREFER_PTHREAD_FLAG ON)
    find_package(Threads REQUIRED)
    find_package(PNG REQUIRED)
    find_package(X11 REQUIRED)
    find_package(OpenGL REQUIRED)
    find_package(GLUT REQUIRED)
    include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
    include_directories(${PNG_INCLUDE_DIR})

endif (CMAKE_HOST_UNIX)


file(COPY  "graphics" DESTINATION ${PROJECT_BINARY_DIR})
include_directories("include")


# Include sub-projects.
add_subdirectory ("Snakes")
