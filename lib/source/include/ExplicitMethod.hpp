/**
 * @file ExplicitMethod.hpp
 * @author Sumun, M. Fadil
 * @brief Explicit finite-difference method
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef EXPLICITMETHOD_HPP
#define EXPLICITMETHOD_HPP

#include "FiniteDifferenceMethod.hpp"

/**
 * @brief Explicit finite-difference method class
 * 
 */
class ExplicitMethod : public FDMethod
{
    public:

        /**
         * @brief Construct a new Explicit Method object
         * 
         * @param PtrPDE_ Pointer to a ParabPDE object
         * @param imax_ Time dicretisation
         * @param jmax_ Spatial discretisation
         */
        ExplicitMethod(ParabPDE* PtrPDE_, int imax_, int jmax_)
            : FDMethod(PtrPDE_, imax_, jmax_) {}
    
        // Coeffficient functions
        double A(int i, int j);
        double B(int i, int j);
        double C(int i, int j);
        double D(int i, int j);

        /**
         * @brief Solve PDE
         * 
         */
        void SolvePDE();

};

#endif /* EXPLICITMETHOD_HPP */
