# Creo l'eseguibile per i test
add_executable(TaskManagerTest
        TaskManagerTest.cpp
        TaskTest.cpp
        ../src/TaskManager.cpp)

# Collego Google Test a questo eseguibile
target_link_libraries(TaskManagerTest GTest::gtest_main)

# Registro i test
include(GoogleTest)
gtest_discover_tests(TaskManagerTest)