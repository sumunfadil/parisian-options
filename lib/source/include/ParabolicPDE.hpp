/**
 * @file ParabolicPDE.hpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef PARABOLICPDE_HPP
#define PARABOLICPDE_HPP

class ParabPDE
{
    public: 
        double T, xl, xu;

        // Coeffficient functions
        virtual double a(double t, double x) = 0;
        virtual double b(double t, double x) = 0;
        virtual double c(double t, double x) = 0;
        virtual double d(double t, double x) = 0;

        // Boundary conditions
        virtual double f(double x) = 0;
        virtual double fu(double t) = 0;
        virtual double fl(double t) = 0;
};

#endif /* PARABOLICPDE_HPP */
