# Abilita testing
enable_testing()

# Trova Google Test tramite vcpkg
find_package(GTest REQUIRED)

# Raccoglie tutti i file di test nella cartella corrente
file(GLOB TEST_SOURCES *.cpp)

# Crea l’eseguibile dei test
add_executable(tests ${TEST_SOURCES})

# Linka la libreria principale (task_lib) e GTest
target_link_libraries(tests
        PRIVATE
        task_lib        # dalla cartella src
        GTest::gtest
        GTest::gtest_main
)

# Fa scoprire automaticamente i test a CTest
include(GoogleTest)
gtest_discover_tests(tests)
