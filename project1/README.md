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
1. operator<<(): overloading the ostream operator. It's a friend function, that is not a member function of Points2D, therefore it doesn't have direct access to size_ and sequence_. It's user defined, so we're just printing out the format desired, i.e: "(1,2)", we can cout << a; directly.

2. operator>>(): overloading the istream operator. It's a friend function, that is not a member function of Points2D, therefore it doesn't have direct access to size_ and sequence_. It's user defined, read in a chain from an input stream (e.g., standard input). Now input stream could directly read data into Points2D object.

3. operator+(): overloading the + operator. It's a friend function, that is not a member function of Points2D, therefore it doesn't have direct access to size_ and sequence_. We need to create an instance of Poitns2d to hold the pair-wise sum of 2 Points2d sequences, and return it.

4. operator[](): overloading the array index operator. User defined. If index location is not found, abort it and throws an error to user.




[References: ] https://en.cppreference.com/w/cpp/language/rule_of_three, https://www.geeksforgeeks.org/rule-of-five-in-cpp/