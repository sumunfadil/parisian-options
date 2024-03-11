/**
 * @file ImplicitMethod.cpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ImplicitMethod.hpp"
#include "Matrix.hpp"
#include "Visitor.hpp"
#include <cmath>

ImplicitScheme::ImplicitScheme(ParabPDE* PtrPDE_, int imax_, int jmax_)
    : FDMethod(PtrPDE_, imax_, jmax_) {}

Vector ImplicitScheme::A(int i, Vector q)
{
    Vector p(jmax+1); 

    p[1] = B(i,1)*q[1] + C(i,1)*q[2];

    for (int j=2; j<jmax-1; j++)
    {
        p[j] = A(i,j)*q[j-1] + B(i,j)*q[j] + C(i,j)*q[j+1];
    }

    p[jmax-1] = A(i,jmax-1)*q[jmax-2] + B(i,jmax-1)*q[jmax-1];

    return p;
}

Vector ImplicitScheme::w(int i)
{
    Vector w(jmax+1);

    w[1] = D(i,1) + A(i,1)*fl(i) - E(i,1)*fl(i-1);

    for (int j=2; j<jmax-1; j++) 
    {
        w[j] = D(i,j);
    }

    w[jmax-1] = D(i,jmax-1) + C(i, jmax-1)*fu(i) - G(i,jmax-1)*fu(i-1);

    return w;
}

Vector ImplicitScheme::accept(Visitor* visitor, int i, Vector q)
{
    return visitor->visit(this, i, q);
}

void ImplicitScheme::SolvePDE() {
    for (int j = 0; j <= jmax; j++) {
        V[imax][j] = f(j);
    }

    for (int i = imax; i > 0; i--) {
        // Use the visitor to solve the system of equations
        Vector q = A(i, V[i]) + w(i);
        V[i - 1] = accept(visitor, i, q);

        V[i - 1][0] = fl(i - 1);
        V[i - 1][jmax] = fu(i - 1);
    }
}
