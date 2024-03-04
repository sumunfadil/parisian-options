/**
 * @file BlackScholesEquation.hpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BLACKSCHOLESEQUATION_HPP    
#define BLACKSCHOLESEQUATION_HPP

#include "ParabolicPDE.hpp"
#include "BlackScholesModel.hpp"
#include "Option.hpp"

class BSEq : public ParabPDE
{
    public: 
        BSModel* PtrModel;
        Option* PtrOption;

        /**
         * @brief Construct a new BSEq object
         * 
         * @param PtrModel_ Pointer to a BSModel object
         * @param PtrOption_ Pointer to an Option object
         */
        BSEq(BSModel* PtrModel_, Option* PtrOption_);

        // Coeffficient functions
        double a(double t, double z);
        double b(double t, double z);
        double c(double t, double z);
        double d(double t, double z);

        // Boundary conditions
        double f(double z);
        double fl(double t);
        double fu(double t);
};

#endif /* BLACKSCHOLESEQUATION_HPP */

