/* CSCI335 Summer 2024
Project_1
Author: Xin (Sue) Sui

points2d.h contains both declaration and implementation

class Points2D is a template class that implements the use of Weiss's Big-Five:
- Constructor
- Destructor
- Copy constructor
- Copy assignment
- Move constructor
- Move assignment

We're also overloading "<<", ">>", "[]", "+" operators.
We'll unittest this class with input file
*/
#ifndef CSCI335_HOMEWORK1_POINTS2D_H_
#define CSCI335_HOMEWORK1_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>
// ADDING A NEW COMMENT
namespace teaching_project
{

    // Place comments that provide a brief explanation of the class,
    // and its sample usage.
    template <typename Object>
    class Points2D
    {

    private:
        // sequence_ is an array pointer that holds array elements of 2, each element is one array
        // sequence_ = [[], [], []] array of arrays
        std::array<Object, 2> *sequence_;
        size_t size_; // Size of sequence_ array

    public:

        /**
        Default constructor of class Points2D
        @post     : Initialize the size_ of the sequence array to 0,
                    and sequence_ array pointer to nullptr.
        */
        Points2D()
        {
            size_ = 0;
            sequence_ = nullptr;
        };


        /**
        Parameterized constructor of class Points2D
        @param item: A tuple in the form of an array size of 2 as element.
        item itself is a tuple item = (1,2)

        @post      : Adds the item to the sequence_ array, 
        Dynamically Allocate memory sequence_ for one element
        (each element itself is an array size 2)
        updated size_ to 1, since adding just one element
        */
        Points2D(const std::array<Object, 2> &item)
        {
            size_ = 1;
            sequence_ = new std::array<Object, 2>[size_];
            sequence_[0] = item;
        }

        /******* Beginning of Weiss's Big-Five *******/

        /**
        Copy constructor of class Points2D
        @param rhs  : Another Points2D object, passed in by reference
        @post       : set the current size_ to rhs's size and
                    dynamically allocate memory for sequence_ array
                    and copy from rhs's sequence array, deep copy.
        */
        Points2D(const Points2D &rhs)
        {
            size_ = rhs.size_;

            sequence_ = new std::array<Object, 2>[size_];
            for (size_t i = 0; i < size_; ++i) {
                sequence_[i] = rhs.sequence_[i];
            }
        };



        /**
        Copy assignment of class Points2D - always a shallow copy
        @param rhs  : Another Points2D object, passed in by reference
        @post       : Create a copy of rhs, and swap copy with *this
                    Now *this contains the the data of rhs. 
        @return     : return a reference to *this, dereferenced this.
        */
        Points2D &operator=(const Points2D &rhs)
        {
            if (this != &rhs)
            {
                Points2D copy = rhs;
                std::swap(*this, copy);
            }
            return *this; // if the same, just return it directly, without swapping
        }



        /**
        Move constructor of class Points2D
        @param rhs  : Another Points2D object, passed in as rvalue reference
        @post       : Transfer the ownwership of rhs to "this", reset rhs to empty
        **/
        Points2D(Points2D &&rhs)
        {
            size_ = rhs.size_;
            sequence_ = std::move(rhs.sequence_);

            rhs.size_ = 0;
            // delete[] rhs.sequence_; //should NOT delete it because it is now owned by 'this'
            rhs.sequence_ = nullptr;
        }


        // Just use std::swap() for all variables.
        /**
        Move-assignment of class Points2D
        @param rhs  : Another Points2D object, passed in as rvalue reference
        @post       : Swap the ownwership of rhs with "this".
        @return     : return a reference to *this, dereferenced this.
        */
        Points2D &operator=(Points2D &&rhs)
        {
            if (this != &rhs)
            {
                size_ = rhs.size_;
                sequence_ = std::move(rhs.sequence_);

                rhs.size_ = 0;
                // delete[] rhs.sequence_; //should NOT delete it because it is now owned by 'this'
                rhs.sequence_ = nullptr;
            }

            return *this;
        }


        /**
        Destructor of class Points2D
        @post     : Reset the size_ of the sequence array to 0,
                    and deallocate sequence_ memory
                    set sequence_ pointer to nullptr.
        */
        ~Points2D()
        {
            size_ = 0;
            // delete[] sequence_;
            sequence_ = nullptr;
        };

        /******* End of Weiss's Big-Five *******/
        

        /******** Beginning of member functions ********/
        /**
        @post      : Getter function, returns the size_ of the sequence_ array.
        @return    : return the size of the sequence array.
        @post      : size of the sequence_ array is updated.
        */
        size_t size() const
        {
            return size_;
        }



        // @location: an index to a location in the sequence.
        // @returns the point at @location.
        // const version.
        // abort() if out-of-range.
        const std::array<Object, 2> &operator[](size_t location) const
        {
            // Code missing.
        }


        //  @c1: A sequence.
        //  @c2: A second sequence.
        //  @return their sum. If the sequences are not of the same size, append the
        //    result with the remaining part of the larger sequence.
        friend Points2D operator+(const Points2D &c1, const Points2D &c2)
        {
            // Code missing.
        }


        /**
        Overloading the << operator.
        @param out          : an ostream object, passed by reference
        @param some_points  : a Points2D object, passed by reference
        @return             : the ostream object after feeding the Points2D elements into it
        @post               : overload the << operator to print the elements in the
        sequence array of the Points2D object that's passed in. Making Points2D objects printable.
        */
        friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points)
        {
            for (int i = 0; i < some_points.size(); i++)
            {
                out << "(" << some_points.sequence_[i][0] << ", " << some_points.sequence_[i][1] << ") ";
            }
            return out;
        }


        /**
        Overloading the >> operator.
        @param in           : an istream object, passed by reference
        @param some_points  : a Points2D object, passed by reference
        @return             : the istream object after feeding the Points2D elements into it
        @post               : overload the >> operator to read in a chain from an input stream (e.g., standard input). 
                            Now input stream could directly read data into Points2D object.
        */
        friend std::istream &operator>>(std::istream &in, Points2D &some_points)
        {
            // first check if some_points sequence array is empty
            if (some_points.sequence_ != nullptr) 
            {
                delete[] some_points.sequence_;
                some_points.sequence_ = nullptr;
            }

            // first number from input is always the size of the sequence array
            // read that in first
            int input_size;
            in >> input_size;

            some_points.size_ = input_size;
            some_points.sequence_ = new std::array<Object, 2>[some_points.size_];

            // Read each point and add to sequence_
            for (size_t i = 0; i < some_points.size(); ++i)
            {
                in >> some_points.sequence_[i][0] >> some_points.sequence_[i][1];
            }

            return in;
        }


        /******** End of member functions ********/
    };

} // namespace teaching_project

#endif // CSCI_335_HOMEWORK1_Points2D_H_