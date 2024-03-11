#include "ThomasAlgorithmVisitor.hpp"
#include "ImplicitMethod.hpp"
#include "CrankNicolsonMethod.hpp"

Vector ThomasAlgorithmVisitor::visit(ImplicitScheme* method, int i, Vector q) {
    int jmax = method->jmax;
    Vector p(jmax + 1);

    // Forward elimination
    Vector alpha(jmax + 1);
    Vector beta(jmax + 1);

    alpha[1] = method->B(i, 1);
    beta[1] = q[1];

    for (int j = 2; j <= jmax; j++) {
        double denom = method->A(i, j - 1) * alpha[j - 1] + method->B(i, j);
        alpha[j] = -method->C(i, j - 1) / denom;
        beta[j] = (q[j] - method->A(i, j - 1) * beta[j - 1]) / denom;
    }

    // Backward substitution
    p[jmax] = beta[jmax];

    for (int j = jmax - 1; j >= 1; j--) {
        p[j] = alpha[j] * p[j + 1] + beta[j];
    }

    return p;
}

Vector ThomasAlgorithmVisitor::visit(CNNMethod* method, int i, Vector q) {
    int jmax = method->jmax;
    Vector p(jmax + 1);

    // Forward elimination
    Vector alpha(jmax + 1);
    Vector beta(jmax + 1);

    alpha[1] = method->B(i, 1);
    beta[1] = q[1];

    for (int j = 2; j <= jmax; j++) {
        double denom = method->A(i, j - 1) * alpha[j - 1] + method->B(i, j);
        alpha[j] = -method->C(i, j - 1) / denom;
        beta[j] = (q[j] - method->A(i, j - 1) * beta[j - 1]) / denom;
    }

    // Backward substitution
    p[jmax] = beta[jmax];

    for (int j = jmax - 1; j >= 1; j--) {
        p[j] = alpha[j] * p[j + 1] + beta[j];
    }

    return p;
}