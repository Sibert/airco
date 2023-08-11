cmake_minimum_required(VERSION 3.11.0)
project(TestProject VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(unittesting)

add_executable(TestProject main.cpp 
  Menu/Menu.cpp 
  Implementation/TemperatureControllerContextImpl.cpp
  Implementation/TemperatureInputImpl.cpp
  Implementation/OutputImpl.cpp
  TemperatureController/Context/TemperatureControllerContext.cpp 
  TemperatureController/States/State.cpp
  TemperatureController/States/IdleState/IdleState.cpp
  TemperatureController/States/CoolingState/CoolingState.cpp
  TemperatureController/States/HeatingState/HeatingState.cpp
  )

include_directories(TestProject PUBLIC 
  Interfaces 
  Menu 
  TemperatureController
  TemperatureController/Context
  TemperatureController/States
  TemperatureController/States/IdleState 
  TemperatureController/States/CoolingState
  TemperatureController/States/HeatingState
  Implementation
  )

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
#target_link_libraries(TestProject PRIVATE Threads::Threads)
