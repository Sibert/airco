# Test project for Daikin
## Scope
### Requirement
Ensure that the temperature in a room is always between a min and max adjustable temperature.
When temp is too low, start heating, when temp is too high start cooling.

### How
1. create a component in cpp + api's 
2. create needed test-cases using google test (stub, mock,..)
3. code must be build with cmake
4. code is available in a git repo

# Rationale
## State machine
A state machine was chosen for this implementation. In this simple example somewhat overkill since the logic in each state is nearly identical, but it allows for very simple expansion (e.g. a cooldown state before switching between heating and cooling, error detection...).

The state machine pattern also allows for very quick and simple unittesting, since the states don't use any platform dependent code. Each state depends on the context class to retrieve data (input values) and perform actions (start/stop heating/cooling). By creating an abstract context class, it's easy to use different implementations. In this case there is an implementation for the unittests and an implementation to make it run on a regular computer. Creating an implementation that runs on a microcontroller becomes trivial.

## TemperatureInput
The temperatureInput class has been made abstract, as to allow portability to different platforms. An implementation can be made to use the console, but an implementation that uses an ADC on a MCU is possible as well. The output class is similar to this

## Unittesting
The unittests are focussed on the states. By testing both the 'entry' and 'exit' functions of each state, the physical behavior of the FSM is tested. The transition logic is tested as well, by performing tests on the 'process' function of each state.

