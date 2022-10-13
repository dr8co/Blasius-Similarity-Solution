#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>

#include "headers/blasius.h"

int main() {
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~ Blasius Numerical Solution ~~~~~~~~~~~~~~~~~~~~~~~~~ \n" << std::endl;
    std::cout << R"(The Blasius Equation: f''' + ff" = 0)" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    // Generate a pseudo-random number for the initial guess of f"(0):
    std::random_device generator;
    std::mt19937 engine{generator()};
    std::uniform_real_distribution<> dist(-10.f, 10.f);
    double random_number = dist(engine);

    // approximating the boundary condition f"(0) with an initial guess (the generated pseudo-random number):
    double fDoublePrime_0{boundaryCondition(random_number)};

    // 0.33205733716392832333

    std::cout << std::setprecision(20) << "\n\t Approximated f\"(0) = " << fDoublePrime_0 << "\n" << std::endl;

    blasius(fDoublePrime_0); //solving the equation using the approximated f"(0).

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "\n\n\t\tTime taken: " << duration.count() << " milliseconds.\n" << std::endl;
    std::cout << "\nRandom number: " << random_number << std::endl;

    return 0;
}