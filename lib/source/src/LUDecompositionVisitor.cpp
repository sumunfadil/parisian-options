#include "LUDecompositionVisitor.hpp"
#include "Matrix.hpp"
#include <vector>

Vector LUDecompositionVisitor::visit(ImplicitScheme* method, int i, Vector q) 
{
    int jmax = method->jmax;
    Vector p(jmax + 1), r(jmax + 1), y(jmax + 1);

    r[1] = method->F(i, 1);
    y[1] = q[1];

    for (int j = 2; j < jmax; j++) 
    {
        r[j] = method->F(i, j) - method->E(i, j) * method->G(i, j - 1) / r[j - 1];
        y[j] = q[j] - method->E(i, j) * y[j - 1] / r[j - 1];
    }

    p[jmax - 1] = y[jmax - 1] / r[jmax - 1];

    for (int j = jmax - 2; j > 0; j--) 
    {
        p[j] = (y[j] - method->G(i, j) * p[j + 1]) / r[j];
    }

    return p;
}

Vector LUDecompositionVisitor::visit(ImplicitScheme* method, int i, Vector q) 
{
    int jmax = method->jmax;
    Vector p(jmax + 1), r(jmax + 1), y(jmax + 1);

    r[1] = method->F(i, 1);
    y[1] = q[1];

    for (int j = 2; j < jmax; j++) 
    {
        r[j] = method->F(i, j) - method->E(i, j) * method->G(i, j - 1) / r[j - 1];
        y[j] = q[j] - method->E(i, j) * y[j - 1] / r[j - 1];
    }

    p[jmax - 1] = y[jmax - 1] / r[jmax - 1];

    for (int j = jmax - 2; j > 0; j--) 
    {
        p[j] = (y[j] - method->G(i, j) * p[j + 1]) / r[j];
    }

    return p;
}


