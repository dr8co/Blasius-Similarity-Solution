#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <filesystem>
#include <cmath>

#include "headers/blasius.h"
#include "headers/Blas.h"

void blasius(double f_p_p) {
    // Parameters for Runge-Kutta
    double k1, k2, k3, k4;
    double l1, l2, l3, l4;
    double m1, m2, m3, m4;

    // Boundary and initial conditions:
    double f{0};     // f(0) = 0
    double f_p{0};   // f'(0) = 0
    double eta{0}; // eta begins at 0

    // Time-step of 0.01 from 0 to 10
    int t{1000};
    double h{0.01};

    // Vectors to store the solution data for eta, f, f' and f"
    std::vector<double> eta_vec, f_vec, fPrime_vec, fDoublePrime_vec;

    for (int i = 0; i <= t; i++) {
        // Applying RK4 to find the next values:
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

        // displaying the solution after each iteration
        std::cout << "eta = " << std::fixed << std::setprecision(10) << eta << ":  f = " << f
                  << ", f\' = " << f_p << ", f\" = " << f_p_p << std::endl;

        // updating the vectors with new values
        eta_vec.push_back(eta);
        f_vec.push_back(f);
        fPrime_vec.push_back(f_p);
        fDoublePrime_vec.push_back(f_p_p);

        // Updating the next values of f, f_p, fDoublePrime_vec and f for the next iteration, as per RK4
        f += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        f_p += (l1 + 2 * l2 + 2 * l3 + l4) / 6;
        f_p_p += (m1 + 2 * m2 + 2 * m3 + m4) / 6;

        eta += h;
    }

    // writing the data to a comma-separated values (csv) file, for storage of the solution.
    std::filesystem::path cwd = std::filesystem::current_path() / "Blasius_solution.csv";
    std::fstream file;

    // open the file in truncation mode and write the data
    file.open(cwd, std::ios::out | std::ios::trunc);
    file << "eta," << "f," << "fPrime," << "fDoublePrime" << std::endl;

    for (int j = 0; j < eta_vec.size(); j++) {
        file << std::setprecision(12) << eta_vec[j] << "," << f_vec[j] << "," << fPrime_vec[j] << ","
             << fDoublePrime_vec[j] << "\n";
    }
    // close the file when done.
    file.close();

    std::filesystem::current_path();
    std::cout << "\nThe solution data has been saved as " << cwd << std::endl;
}

// a function to solve apply Runge-Kutta 4 to solve the Blasius equation.
double rungeKutta(double f_p_p) {
    // Parameters for Runge-Kutta
    double k1, k2, k3, k4;
    double l1, l2, l3, l4;
    double m1, m2, m3, m4;

    // Boundary and initial conditions:
    double f{0};     // f(0) = 0
    double f_p{0};   // f'(0) = 0
    double eta{0}; // eta begins at 0

    // Time-step of 0.01 from 0 to 10
    const int t{1000};
    const double h{0.01};

    for (int i = 0; i <= t; i++) {
        // Applying RK4 to find the next values:
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

        // Updating the next values of f, fPrime, f_p_p and f for the next iteration
        f += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        f_p += (l1 + 2 * l2 + 2 * l3 + l4) / 6;
        f_p_p += (m1 + 2 * m2 + 2 * m3 + m4) / 6;

        eta += h;
    }
    return f_p;
}

double boundaryCondition(double initialGuess) {
    double guess{fabs(initialGuess)};
    double alpha{0.001};

    while (guess > 1) {
        guess = sqrt(guess);
    }

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