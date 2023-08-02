cmake_minimum_required(VERSION 3.11.0)
project(TestProject VERSION 0.1.0 LANGUAGES C CXX)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(TemperatureControllerTest unittesting/TemperatureControllerTest.cpp TemperatureController/TemperatureController.cpp)
target_link_libraries(TemperatureControllerTest GTest::gtest_main)

include(GoogleTest)
add_test(Name TemperatureControllerTest Command TemperatureControllerTest)

add_executable(TestProject main.cpp Menu/Menu.cpp TemperatureController/TemperatureController.cpp)
include_directories(TestProject PUBLIC Menu TemperatureController)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(TestProject PRIVATE Threads::Threads)
