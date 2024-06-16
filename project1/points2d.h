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
        }

        // Copy-constructor.
        Points2D(const Points2D &rhs)
        {
        }

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

        ~Points2D()
        {
            size_ = 0;
            sequence_ = nullptr;
        }

        // End of big-five.

        // One parameter constructor.
        Points2D(const std::array<Object, 2> &item)
        {
            sequence_ = &item;
        }

        // getter
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
            out << "(" << (*some_points.sequence_)[0] << ", " << (*some_points.sequence_)[1] << ")";
            return out;
        }

        // Overloading the >> operator.
        // Read a chain from an input stream (e.g., standard input).
        friend std::istream &operator>>(std::istream &in, Points2D &some_points)
        {
            // Code missing.
        }

    private:
        // *sequence_ is a pointer that points to an array of size 2
        const std::array<Object, 2> *sequence_;

        // Size of sequence.
        size_t size_;
    };

} // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_Points2D_H_