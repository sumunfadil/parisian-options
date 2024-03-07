#include "BlackScholesModel.hpp"
#include "Option.hpp"
#include "BlackScholesEquation.hpp"
#include "ExplicitMethod.hpp"
#include <iostream>

using namespace std;

int main()
{
    double S0 = 100.0, r = 0.05, sigma = 0.2;
    BSModel Model(S0, r, sigma);

    double K = 100.0, T=1./12., zl = 0.0, zu = 2.0*S0;
    Put EuropeanPut(K,T,zl,zu);

    BSEq BSPDE(&Model, &EuropeanPut);

    int imax = 3000, jmax = 1000;
    ExplicitMethod ExplicitMethod(&BSPDE, imax, jmax);

    ExplicitMethod.SolvePDE();

    cout << "Price of European put option using explicit finite-difference scheme:";
    cout << "\nPrice: " << ExplicitMethod.v(0.0, S0) << endl;
    return 0;
}