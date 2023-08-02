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
## Input
The input is a seperate thread. Much like a real embedded system, inputs shouldn't block execution of the code but usin 'cin' does, hence the choice to put it in a thread

## Menu
I made the menu a seperate class, in this example this might seem overkill. This has been done because I like to always write easily expandable code. In this case, the menu class could be expanded to contain submenus and handle input validation

## TemperatureController
The temperature controller itself contains references to its three inputs, making it simple to just 'run' it.
It prints it's state whenever it changes as an output and also returns it's state on the run function.
The run function could be easily expanded to implement a PID loop or functions to check if the current temperature changes within a reasonable timeframe