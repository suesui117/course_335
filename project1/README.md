# Project1 Points2D class:
## Purpose of the project is to revisit template class, constructors and to implement C++'s "The Rule of Big Five" which are user-defined functions to properly handle memory, such as memory allocation and deallocation.

### Part1: Implement default/parameterized constructors and Weiss's Big-Five.
1. Default constructor: initialize private variables to 0 and nullptr.

2. Parameterized constructor: one parameter, add a pair of points to the sequence array which is dynamically allocated of size 1.

3. Copy-constructor: user-defined, perform a deep copy. Allow instantiation of a Points2d object by copying another instance of Points2D.

4. Copy-assignment: user-defined, perform a deep copy. Allow the current instance of a class to copy another Points2D object.

5. Move-constructor: user-defined. Transfer the ownwership of another Points2d object to a new Points2d object to be instantiated.

6. Move-assignment: user-defined. Transfer the ownwership of another Points2d object to an existing Points2d object.

7. Destructor: Deallocate dynamically allocated memory and set pointer to null, to avoid dangling pointer. In this project, we used raw pointers.


### Part2 - Overloading operators: <<, >>, [], +




[References: ](https://en.cppreference.com/w/cpp/language/rule_of_three)
(https://www.geeksforgeeks.org/rule-of-five-in-cpp/)