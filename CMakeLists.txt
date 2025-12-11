cmake_minimum_required(VERSION 4.0)
project(TaskProject LANGUAGES CXX)

# Imposta standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Aggiunge la cartella src (crea task_lib)
add_subdirectory(src)

# ------------------------
# ESEGUIBILE PRINCIPALE
# ------------------------
add_executable(TaskApp main.cpp)

# Linka la libreria principale
target_link_libraries(TaskApp
        PRIVATE
        task_lib
)

# ------------------------
# TESTING
# ------------------------
# Aggiunge la cartella tests, dove c'è il CMakeLists dei test
add_subdirectory(tests)



