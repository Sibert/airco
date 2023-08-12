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
## Platform independence
The code was written to be as portable as possible. The logic of the code is fully platform independent.
By making use of abstract hardware classes (Output and TemperatureInput), the implementations can be changed at compile time. Adding new implementations should in theory be quick and easy. The instances of these hardware classes are created by an implementation of the HALInterface, which is also has an implementation depending on the platform.

## Testing
As the hardware classes are abstact, it's a small feat to create mock implementations of these classes.
This makes the testing easy by mocking the functions of these classes. This in turns allow for a test to expect certain calls or return specific values on mocked functions

