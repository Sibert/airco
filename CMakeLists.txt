cmake_minimum_required(VERSION 3.11.0)
project(TestProject VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(unittesting)

set(BUILD_TARGET "linux")

if (BUILD_TARGET  STREQUAL "linux")
  set(HAL_SOURCE 
    HAL/Linux/Impl/HALImpl.cpp
    HAL/Linux/Impl/TemperatureInputImpl/TemperatureInputImpl.cpp
    HAL/Linux/Impl/OutputImpl/OutputLinuxImpl.cpp
    HAL/Linux/Menu/Menu.cpp 
  )
  set(HAL_INCLUDE 
    HAL/Linux/Impl
    HAL/Linux/Impl/TemperatureInputImpl
    HAL/Linux/Impl/OutputImpl
    HAL/Linux/Menu 
  )
elseif (BUILD_TARGET STREQUAL "STM")
  set(HAL_SOURCE 
  HAL/STM/HALImpl.cpp
  HAL/STM/TemperatureInputSTMImpl.cpp
  HAL/STM/OutputSTMImpl.cpp
  )
  set(HAL_INCLUDE 
  HAL/STM
  )
endif()

if(DEFINED HAL_SOURCE AND DEFINED HAL_INCLUDE)
  add_library(HALLib HAL/HALInterface.cpp ${HAL_SOURCE})
  target_include_directories(HALLib PUBLIC HAL ${HAL_INCLUDE})
else()
  message(FATAL_ERROR "Either 'HAL_SOURCE' or 'HAL_INCLUDE' was not defined")
endif()

add_executable(main main.cpp 
  TemperatureController/TemperatureController.cpp
)

include_directories(main PUBLIC
  Interfaces 
  TemperatureController
)

target_link_libraries(main HALLib)