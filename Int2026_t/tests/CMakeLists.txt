include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/releases/download/v1.16.0/googletest-1.16.0.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP ON
    FIND_PACKAGE_ARGS NAMES GTest
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
  ${PROJECT_NAME}_tests
  conversion_tests.cpp
  arithmetic_tests.cpp
  comparison_tests.cpp
  output_tests.cpp
  edge_cases_tests.cpp
  compatibility_tests.cpp
)

target_link_libraries(
  ${PROJECT_NAME}_tests PRIVATE
  number
  GTest::gtest_main
)

target_compile_features(${PROJECT_NAME}_tests PRIVATE cxx_std_23)
target_include_directories(${PROJECT_NAME}_tests PRIVATE ${PROJECT_SOURCE_DIR})

include(GoogleTest)

gtest_discover_tests(${PROJECT_NAME}_tests NO_PRETTY_VALUES)
