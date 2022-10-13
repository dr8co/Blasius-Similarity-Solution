/**
* classname.h: header file for Class_Name
* Author:  Ian Duncan
*      with assistance from:
*
* Description of the role or purpose of objects of this class goes here
*
* Constructors:
*      constructor prototype 1
*          Description of constructor, e.g., copy constructor
*
*      constructor prototype 2
*          Description of constructor, e.g., copy constructor
*
* Public Member Functions:
*
*      f_1
*        precondition:
*        postcondition:
*          Description of what the function does, what input it expects,
*              what output it generates, what it returns.
*
*      f_2
*        precondition:
*        postcondition:
*          Description of what the function does, what input it expects,
*              what output it generates, what it returns.
*/

#ifndef BLASIUS_BLAS_H
#define BLASIUS_BLAS_H

namespace blas {

    class Blas {
    public:
        Blas() = default;
        virtual ~Blas() = default;

        static double
        f_1([[maybe_unused]] double a, [[maybe_unused]] double b, double c, [[maybe_unused]] double d) {
            return c;
        }

        static double
        f_2([[maybe_unused]] double a, [[maybe_unused]] double b, [[maybe_unused]] double c, double d) {
            return d;
        }

        static double f_3([[maybe_unused]] double a, double b, [[maybe_unused]] double c, double d) {
            return -b * d / 2;
        }
    };

} // blas

#endif // BLASIUS_BLAS_H
