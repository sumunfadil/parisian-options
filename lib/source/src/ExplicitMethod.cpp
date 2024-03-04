/**
 * @file ExplicitMethod.cpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ExplicitMethod.hpp"

double ExplicitMethod::A(int i, int j)
{
    return dt*(b(i,j)/2.0-a(i,j)/dx)/dx;
}

double ExplicitMethod::B(int i, int j)
{
    return 1.0 - dt*c(i,j) + 2.0*dt*a(i,j)/(dx*dx);
}

double ExplicitMethod::C(int i, int j)
{
    return -dt*(b(i,j)/2.0 + a(i,j)/dx)/dx;
}

double ExplicitMethod::D(int i, int j)
{
    return -dt*d(i,j);
}

void ExplicitMethod::SolvePDE()
{
    for (int j=0; j<=jmax; j++) 
    {
        V[imax][j] = f(j);
    }

    for (int i=imax; i>0; i--)
    {
        V[i-1][0] = fl(i-1);
        V[i-1][jmax] = fu(i-1);

        for (int j=1; j<jmax; j++)
        {
            V[i-1][j] = A(i,j)*V[i][j-1] + B(i,j)*V[i][j];
                        + C(i,j)*V[i][j+1] + D(i,j);
        }
    }

}

