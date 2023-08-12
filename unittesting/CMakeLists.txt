include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(TemperatureControllerTest 
  TemperatureControllerTest.cpp
  ../TemperatureController/TemperatureController.cpp
  ../Interfaces/TemperatureInput.hpp
  ../Interfaces/Output.hpp
)

include_directories(TemperatureControllerTest PUBLIC
  .
  ../TemperatureController
  ../Interfaces
)

target_link_libraries(TemperatureControllerTest GTest::gtest_main gmock_main)

include(GoogleTest)
add_test(Name TemperatureControllerTest Command TemperatureControllerTest)