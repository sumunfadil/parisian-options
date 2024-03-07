/**
 * @file ExplicitLCP.cpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ExplicitLCP.hpp"

void ExplicitLCP::SolveLCP()
{
    for (int j=0; j<=jmax; j++)
    {
        V[imax][j] = f(j);
        if (V[imax][j] < g(imax, j)) 
        {
            V[imax][j] = g(imax, j);
        }
    }

    for (int i=imax; i>0; i--)
    {
        V[i-1][0] = fl(i-1);
        V[i-1][jmax] = fu(i-1);

        for (int j=1; j<jmax; j++)
        {
            V[i-1][j] = A(i,j)*V[i][j-1] + B(i,j)*V[i][j] + C(i,j)*V[i][j+1] + D(i,j);
        }

        for (int j=0; j<=jmax; j++)
        {
            if(V[i-1][j] < g(i-1,j))
            {
                V[i-1][j] = g(i-1,j);
            }
        }
    }
}