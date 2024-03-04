/**
 * @file ImplicitMethod.hpp
 * @author Sumun, M. Fadil
 * @brief Implicit Method
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef IMPLICITMETHOD_HPP
#define IMPLICITMETHOD_HPP

#include "FiniteDifferenceMethod.hpp"
#include "Matrix.hpp"

class ImplicitScheme : public FDMethod
{
    public:

        // Constructor
        ImplicitScheme(ParabPDE* PtrPDE_, int imax_, int jmax_)
            : FDMethod(PtrPDE_, imax_, jmax_) {}

        virtual double A(int i, int j) = 0;
        virtual double B(int i, int j) = 0;
        virtual double C(int i, int j) = 0;
        virtual double D(int i, int j) = 0;
        virtual double E(int i, int j) = 0;
        virtual double F(int i, int j) = 0;
        virtual double G(int i, int j) = 0;

        Vector w(int i);
        Vector A(int i, Vector q);

        Vector LUDecomposition(int i, Vector q);

        void SolvePDE();
};

#endif /* IMPLICITMETHOD_HPP */
