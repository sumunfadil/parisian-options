/**
 * @file FDMethod.hpp
 * @author Sumun, M. Fadil
 * @brief Finite-difference method for Parabolic PDEs
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef FINITEDIFFERENCEMETHOD_HPP
#define FINITEDIFFERENCEMETHOD_HPP

#include <vector>
#include "ParabolicPDE.hpp"

using namespace std;
typedef vector<double> Vector;

class FDMethod
{
    public:
        ParabPDE* PtrPDE;
        int imax, jmax;
        double dx, dt;

        vector<Vector> V;

        // Constructor
        FDMethod(ParabPDE* PtrPDE_, int imax_, int jmax_);

        double t(double i);
        double x(int j);

        // Coeffficient functions
        double a(double i, int j);
        double b(double i, int j);
        double c(double i, int j);
        double d(double i, int j);

        // Boundary conditions
        double f(int j);
        double fu(int i);
        double fl(int i);

        double v(double t, double x);
};

#endif /* FINITEDIFFERENCEMETHOD_HPP */
