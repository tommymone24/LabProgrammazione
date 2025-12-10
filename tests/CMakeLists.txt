add_executable(runTests
        test_tasks.cpp
        ../src/tasks.cpp
)

target_link_libraries(runTests gtest gtest_main)
