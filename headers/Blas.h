/**
 * @file Blas.h
 * @author Ian Duncan (dr8co@duck.com)
 * @brief Header file for namespace blas/class Blas
 * @version 0.1
 * @date 2022-10-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BLASIUS_BLAS_H
#define BLASIUS_BLAS_H

namespace blas {

    /**
     * @brief the class Blas contains three linear equations
     * derived from the Blasius equation.
     * To avoid function overloading (and reduce code size), the functions
     * were declared with unused parameters so that all the calls to the
     * three functions would be uniform and easier to debug.
     * The [[maybe_unused]] attribute was used to suppress compiler warnings
     * for the unused parameters.
     */
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
