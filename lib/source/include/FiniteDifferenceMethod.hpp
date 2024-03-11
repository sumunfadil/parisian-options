/**
 * @file FiniteDifferenceMethod.hpp
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

        // Virtual destrctor
        virtual ~FDMethod() {} 

        // Pointer to a parabolic PDE object
        ParabPDE* PtrPDE;
        // The number of time and spatial intervals
        int imax, jmax;
        // Step sizes
        double dx, dt;

        // A matrix of the value V(t_i,x_j) for each i,j
        vector<Vector> V;

        /**
         * @brief Construct a new FDMethod object
         * 
         * @param PtrPDE_ Pointer to a parabolic PDE
         * @param imax_ Time discretisation
         * @param jmax_ Spatial discretisation
         */
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

        /**
         * @brief Calculates v(t,x) using interpolation
         * 
         * @param t Any time in [0,T]
         * @param x Any value in [x1,xu]
         * @return double 
         */
        double v(double t, double x);
};

#endif /* FINITEDIFFERENCEMETHOD_HPP */
