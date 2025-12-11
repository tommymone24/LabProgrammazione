cmake_minimum_required(VERSION 4.0)
project(LabProgrammazione)

set(CMAKE_CXX_STANDARD 17)

# --- 1. SCARICA GOOGLE TEST (Mettilo qui!) ---
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# Fix per Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
# ---------------------------------------------

enable_testing()

# --- 2. ORDINA DI ENTRARE NELLE CARTELLE ---
add_subdirectory(src)
add_subdirectory(tests)


