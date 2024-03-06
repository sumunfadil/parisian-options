/**
 * @file FiniteDifferenceMethod.cpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "FiniteDifferenceMethod.hpp"

FDMethod::FDMethod(ParabPDE* PtrPDE_, int imax_, int jmax_)
{
    PtrPDE = PtrPDE_;
    imax = imax_;
    jmax = jmax_;

    dx = (PtrPDE->xu - PtrPDE->xl)/jmax;
    dt = PtrPDE->T/imax;

    // V has dimension (imax+1)x(jmax+1)
    V.resize(imax+1);

    for (int i=0; i <= imax; i++) 
    {
        V[i].resize(jmax+1);
    }
}

/*
    Space and time discretisation
*/

double FDMethod::t(double i)
{
    return dt * i;
}

double FDMethod::x(int j)
{
    return PtrPDE->xl+dx*j;
}

/*
    Coeffficient functions
*/

double FDMethod::a(double i, int j)
{
    return PtrPDE->a(t(i),x(j));
}

double FDMethod::b(double i, int j)
{
    return PtrPDE->b(t(i),x(j));
}

double FDMethod::c(double i, int j)
{
    return PtrPDE->c(t(i),x(j));
}

double FDMethod::d(double i, int j)
{
    return PtrPDE->d(t(i),x(j));
}

/*
    Boundary conditions
*/

double FDMethod::f(int j)
{
    return PtrPDE->f(x(j));
}

double FDMethod::fu(int i)
{
    return PtrPDE->fu(t(i));
}

double FDMethod::fl(int i)
{
    return PtrPDE->fl(t(i));
}


double FDMethod::v(double t, double x)
{
    // Find nearest index (i,j) from (t_i,x_j) closest to (t,x) by 
    // casting to integer 
    int i = (int) (t/dt);
    int j = (int) ((x-PtrPDE->xl)/dx);

    // Compute weights
    double l1 = (t-FDMethod::t(i))/dt, l0 = 1.0-l1;
    double w1 = (x-FDMethod::x(j))/dx, w0 = 1.0-w1;

    // Apply interpolation
    return l1*w1*V[i+1][j+1] + l1*w0*V[i+1][j]
          +l0*w1*V[i][j+1] + l0*w0*V[i][j];
}



