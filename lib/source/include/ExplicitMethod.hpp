/**
 * @file ExplicitMethod.hpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef EXPLICITMETHOD_HPP
#define EXPLICITMETHOD_HPP

#include "FDMethod.hpp"

class ExplicitMethod : public FDMethod
{
    public:
        // Constructor
        ExplicitMethod(ParabPDE* PtrPDE_, int imax_, int jmax_)
            : FDMethod(PtrPDE_, imax_, jmax_) {}
    
        // Coeffficient functions
        double A(int i, int j);
        double B(int i, int j);
        double C(int i, int j);
        double D(int i, int j);

        void SolvePDE();

};

#endif /* EXPLICITMETHOD_HPP */
