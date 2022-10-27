/**
 * @file blasius.cpp
 * @author Ian Duncan (dr8co@duck.com)
 * @brief Source file for functions
 * @version 0.1
 * @date 2022-10-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <filesystem>
#include <cmath>

#include "headers/blasius.h"
#include "headers/Blas.h"

/**
 * @brief
 * rungeKutta function applies Runge-Kutta 4 to solve the Blasius equation.
 * This function takes a nominal value of f"(0) and computes f'(10), which
 * is the return value.
 * Since f'(infinity) = 1 (Boundary condition), 10 is sufficiently large enough
 * to satisfy the boundary condition.
 * 
 * @param f_p_p (double): a nominal value of f"(0) Boundary Condition (B.C.)
 * @return f_p (double) : f'(10) computed by applying the above B.C.
 */
double rungeKutta(double f_p_p) {
    // Parameters for Runge-Kutta
    double k1, k2, k3, k4;
    double l1, l2, l3, l4;
    double m1, m2, m3, m4;

    // Boundary and initial conditions
    double f{0};        // f(0) = 0
    double f_p{0};      // f'(0) = 0
    double eta{0};      // eta begins at 0

    // Time-step of 0.01 from 0 to 10 (h * t = 10)
    const int t{1000};
    const double h{0.01};

    for (int i = 0; i <= t; ++i) {
        // Apply Runge-Kutta 4 (RK4) to solve the system of equations for one time-step
        k1 = h * blas::Blas::f_1(eta, f, f_p, f_p_p);
        l1 = h * blas::Blas::f_2(eta, f, f_p, f_p_p);
        m1 = h * blas::Blas::f_3(eta, f, f_p, f_p_p);

        k2 = h * blas::Blas::f_1((eta + 0.5 * h), (f + 0.5 * k1), (f_p + 0.5 * l1), (f_p_p + 0.5 * m1));
        l2 = h * blas::Blas::f_2((eta + 0.5 * h), (f + 0.5 * k1), (f_p + 0.5 * l1), (f_p_p + 0.5 * m1));
        m2 = h * blas::Blas::f_3((eta + 0.5 * h), (f + 0.5 * k1), (f_p + 0.5 * l1), (f_p_p + 0.5 * m1));

        k3 = h * blas::Blas::f_1((eta + 0.5 * h), (f + 0.5 * k2), (f_p + 0.5 * l2), (f_p_p + 0.5 * m2));
        l3 = h * blas::Blas::f_2((eta + 0.5 * h), (f + 0.5 * k2), (f_p + 0.5 * l2), (f_p_p + 0.5 * m2));
        m3 = h * blas::Blas::f_3((eta + 0.5 * h), (f + 0.5 * k2), (f_p + 0.5 * l2), (f_p_p + 0.5 * m2));

        k4 = h * blas::Blas::f_1((eta + h), (f + k3), (f_p + l3), (f_p_p + m3));
        l4 = h * blas::Blas::f_2((eta + h), (f + k3), (f_p + l3), (f_p_p + m3));
        m4 = h * blas::Blas::f_3((eta + h), (f + k3), (f_p + l3), (f_p_p + m3));

        // Update the values of f, f_p, and f_p_p
        f += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        f_p += (l1 + 2 * l2 + 2 * l3 + l4) / 6;
        f_p_p += (m1 + 2 * m2 + 2 * m3 + m4) / 6;

        // Update eta
        eta += h;
    }
    return f_p;
}

/**
 * @brief
 * the adjustGuess function adjusts the initial guess of f"(0) Boundary condition until it
 * satisfies the f'(infinity) = 1, with a tolerance of 10^-12.
 * alpha dictates the rate at which the guess is adjusted. While larger alpha yields
 * results faster, these results are less accurate. Smaller alpha is preferred for accuracy of
 * the solution.
 * However, be warned, as alpha <= 0.001 (as well as alpha >= 0.1) may yield UNSTABLE results.
 *
 * @param initialGuess the initial guess for f"(0).
 *
 * @return a more accurate f"(0).
 */
double adjustGuess(double initialGuess) {
    double guess{fabs(initialGuess)};
    double alpha{0.001};

    // Reduce the scope of the initial guess
    while (guess > 1) {
        guess = sqrt(guess);
    }

    // Adjust the guess until it is optimum
    if (guess < 1) {
        while (1 - rungeKutta(guess) >= 1e-12) {
            guess += alpha * (1 - rungeKutta(guess));
        }

    } else {
        while ((rungeKutta(guess) - 1) >= 1e-12) {
            guess += alpha * (1 - rungeKutta(guess));
        }
    }

    return guess;
}

/**
 * @brief
 * This function solves the Blasius equation using obtained f"(0) boundary condition.
 * Notice that it is an overloaded (extended, rather) version of the rungeKutta function above.
 * This function further processes the solution and stores into a file,
 * where it can be accessed and evaluated.
 *
 * @param f_p_p the optimum f"(0) from the above algorithms.
 */
void blasius(double f_p_p) {
    // Parameters for Runge-Kutta
    double k1, k2, k3, k4;
    double l1, l2, l3, l4;
    double m1, m2, m3, m4;

    // Boundary and initial conditions:
    double f{0};        // f(0) = 0
    double f_p{0};      // f'(0) = 0
    double eta{0};      // eta begins at 0

    // Time-step of 0.01 from 0 to 10
    int t{1000};
    double h{0.01};

    // Vectors to store the solution data for eta, f, f' and f"
    std::vector<double> eta_vec, f_vec, fPrime_vec, fDoublePrime_vec;

    for (int i = 0; i <= t; ++i) {
        // Apply RK4 to solve the system of equations.
        k1 = h * blas::Blas::f_1(eta, f, f_p, f_p_p);
        l1 = h * blas::Blas::f_2(eta, f, f_p, f_p_p);
        m1 = h * blas::Blas::f_3(eta, f, f_p, f_p_p);

        k2 = h * blas::Blas::f_1((eta + 0.5 * h), (f + 0.5 * k1), (f_p + 0.5 * l1), (f_p_p + 0.5 * m1));
        l2 = h * blas::Blas::f_2((eta + 0.5 * h), (f + 0.5 * k1), (f_p + 0.5 * l1), (f_p_p + 0.5 * m1));
        m2 = h * blas::Blas::f_3((eta + 0.5 * h), (f + 0.5 * k1), (f_p + 0.5 * l1), (f_p_p + 0.5 * m1));

        k3 = h * blas::Blas::f_1((eta + 0.5 * h), (f + 0.5 * k2), (f_p + 0.5 * l2), (f_p_p + 0.5 * m2));
        l3 = h * blas::Blas::f_2((eta + 0.5 * h), (f + 0.5 * k2), (f_p + 0.5 * l2), (f_p_p + 0.5 * m2));
        m3 = h * blas::Blas::f_3((eta + 0.5 * h), (f + 0.5 * k2), (f_p + 0.5 * l2), (f_p_p + 0.5 * m2));

        k4 = h * blas::Blas::f_1((eta + h), (f + k3), (f_p + l3), (f_p_p + m3));
        l4 = h * blas::Blas::f_2((eta + h), (f + k3), (f_p + l3), (f_p_p + m3));
        m4 = h * blas::Blas::f_3((eta + h), (f + k3), (f_p + l3), (f_p_p + m3));

        // print the solution for each value of eta
        std::cout << "eta = " << std::fixed << std::setprecision(10) << eta << ":  f = " << f
                  << ", f\' = " << f_p << ", f\" = " << f_p_p << std::endl;

        // update the solution data
        eta_vec.push_back(eta);
        f_vec.push_back(f);
        fPrime_vec.push_back(f_p);
        fDoublePrime_vec.push_back(f_p_p);

        // Update f, f_p, and f_p_p
        f += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        f_p += (l1 + 2 * l2 + 2 * l3 + l4) / 6;
        f_p_p += (m1 + 2 * m2 + 2 * m3 + m4) / 6;

        // update eta
        eta += h;
    }

    // writing the data to a comma-separated values (csv) file, for storage of the solution.
    std::filesystem::path file_path = std::filesystem::current_path() / "Blasius_solution.csv";
    std::fstream file;

    // open the file in truncation mode and write the data.
    file.open(file_path, std::ios::out | std::ios::trunc);
    file << "eta," << "f," << "fPrime," << "fDoublePrime" << std::endl;

    for (int j = 0; j < eta_vec.size(); ++j) {
        file << std::setprecision(12) << eta_vec[j] << "," << f_vec[j] << "," << fPrime_vec[j] << ","
             << fDoublePrime_vec[j] << "\n";
    }
    // close the file when done.
    file.close();

    // show the path to the saved data.
    std::cout << "\nThis data has been saved as " << file_path << std::endl;
}