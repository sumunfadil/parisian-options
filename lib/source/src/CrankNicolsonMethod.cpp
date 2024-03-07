/**
 * @file CrankNicolsonMethod.cpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "CrankNicolsonMethod.hpp"

double CNNMethod::A(int i, int j)
{
    return 0.5*dt*(b(i-0.5,j)/2.0 - a(i-0.5,j)/dx)/dx;
}

double CNNMethod::B(int i, int j)
{
    return 1.0+0.5*dt*(2.0*a(i-0.5,j)/(dx*dx) - c(i-0.5,j));
}

double CNNMethod::C(int i, int j)
{
    return -0.5*dt*(b(i-0.5,j)/2.0 + a(i-0.5,j)/dx)/dx;
}

double CNNMethod::D(int i, int j)
{
    return -dt*d(i-0.5,j);
}

double CNNMethod::E(int i, int j)
{
    return -A(i,j);
}

double CNNMethod::F(int i, int j)
{
    return 2.0-B(i,j);
}

double CNNMethod::G(int i, int j)
{
    return -C(i,j);
}


