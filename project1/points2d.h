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
    public:
        // Default "big five" -- you have to alter them for your assignment.
        // That means that you will remove the "= default" statement.
        //  and you will provide an implementation.

        // Zero-parameter constructor.
        // Set size to 0.
        Points2D()
        {
            size_ = 0;
            sequence_ = nullptr;
        };

        // Copy-constructor.
        Points2D(const Points2D &rhs) = default;

        // Copy-assignment. If you have already written
        // the copy-constructor and the move-constructor
        // you can just use:
        // {
        // Points2D copy = rhs;
        // std::swap(*this, copy);
        // return *this;
        // }
        Points2D &operator=(const Points2D &rhs) = default;

        // Move-constructor.
        Points2D(Points2D &&rhs) = default;

        // Move-assignment.
        // Just use std::swap() for all variables.
        Points2D &operator=(Points2D &&rhs) = default;

        ~Points2D() = default;

        // End of big-five.

        // One parameter constructor.
        Points2D(const std::array<Object, 2> &item)
        {
            // updating size to 1, since adding just one element
            size_ = 1;
            // Dynamically Allocate memory sequence_ for one element (each element itself is an array size 2)
            sequence_ = new std::array<Object, 2>[size_];
            sequence_[0] = item; // item itself is a tuple item = (1,2)
        }

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

        // Overloading the << operator.
        friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points)
        {
            for (int i = 0; i < some_points.size(); i++)
            {
                out << "(" << some_points.sequence_[i][0] << ", " << some_points.sequence_[i][1] << ") ";
            }
            return out;
        }

        // Overloading the >> operator.
        // Read a chain from an input stream (e.g., standard input).
        friend std::istream &operator>>(std::istream &in, Points2D &some_points)
        {
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

    private:
        // Sequence of points.
        std::array<Object, 2> *sequence_; // sequence_ is an array pointer that holds array elements of 2, each element is one array
        // sequence_ = [[], [], []] array of arrays
        // Size of sequence.
        size_t size_;
    };

} // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_Points2D_H_