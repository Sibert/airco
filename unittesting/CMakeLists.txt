include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(TemperatureControllerTest 
  IdleStateTest.cpp 
  CoolingStateTest.cpp
  HeatingStateTest.cpp
  ../TemperatureController/Context/TemperatureControllerContext.cpp 
  ../TemperatureController/States/State.cpp
  ../TemperatureController/States/IdleState/IdleState.cpp
  ../TemperatureController/States/CoolingState/CoolingState.cpp
  ../TemperatureController/States/HeatingState/HeatingState.cpp
  )

include_directories(TemperatureControllerTest PUBLIC
  .
  ../TemperatureController/Context 
  ../TemperatureController/States 
  ../TemperatureController/States/IdleState 
  ../TemperatureController/States/CoolingState
  ../TemperatureController/States/HeatingState
  ../Interfaces 
  ../Mocks
  )

target_link_libraries(TemperatureControllerTest GTest::gtest_main gmock_main)

include(GoogleTest)
add_test(Name TemperatureControllerTest Command TemperatureControllerTest)