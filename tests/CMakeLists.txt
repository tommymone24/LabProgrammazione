# Crea l'eseguibile per i test
# NOTA: Devi includere i file .cpp che vuoi testare prendendoli dalla cartella src (../src/...)
add_executable(TaskManagerTest
        MainTest.cpp
        TaskManagerTest.cpp
        TaskTest.cpp
        ../src/TaskManager.cpp
        ../src/Task.h)

# Collega Google Test a questo eseguibile
target_link_libraries(UnitTests GTest::gtest_main)

# Registra i test
include(GoogleTest)
gtest_discover_tests(UnitTests)