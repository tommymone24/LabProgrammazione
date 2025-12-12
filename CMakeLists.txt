cmake_minimum_required(VERSION 4.0)
project(LabProgrammazione)

set(CMAKE_CXX_STANDARD 17)
add_executable(LabProgrammazione main.cpp
                src/TaskManager.cpp)


# SCARICO GOOGLE TEST
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.14.0
)
# Fix per Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

# ORDINO DI ENTRARE NELLE CARTELLE
add_subdirectory(src)
add_subdirectory(tests)


