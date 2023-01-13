/**
 * @file blasius.h
 * @author Ian Duncan (dr8co@duck.com)
 * @brief header file for function prototypes
 * @version 0.1
 * @date 2022-10-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BLASIUS_BLASIUS_H
#define BLASIUS_BLASIUS_H

#define TOL 1e-12

// function prototypes:
double adjustGuess(double initialGuess);

void blasius(double f_p_p);

#endif //BLASIUS_BLASIUS_H
