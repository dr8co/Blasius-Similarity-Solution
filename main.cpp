/**
 * @file main.cpp
 * @author Ian Duncan (dr8co@duck.com)
 * @brief entry point for the project
 * @version 0.1
 * @date 2022-10-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <iomanip>
#include <random>

#include "blasius.h"

int main() {
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~ Blasius Numerical Solution ~~~~~~~~~~~~~~~~~~~~~~~~~ \n" << std::endl;
    std::cout << R"(The Blasius Equation: 2f''' + ff" = 0)" << std::endl;

    // Generate a pseudo-random number for the initial guess of f"(0):
    std::random_device generator;
    std::mt19937 engine{generator()};
    std::uniform_real_distribution<> dist(-10.f, 10.f);
    double random_number{dist(engine)};

    // Use the random number as the initial guess of f"(0) to find the optimum f"(0)
    double fDoublePrime_0{adjustGuess(random_number)};

    // print the evaluated optimum of f"(0)
    std::cout << std::setprecision(20) << "\n\t Approximated f\"(0) = " << fDoublePrime_0 << "\n" << std::endl;

    // solve the Blasius equation using the optimum f"(0)
    blasius(fDoublePrime_0);

    return 0;
}