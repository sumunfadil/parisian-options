/**
 * @file BlackScholesFormula.cpp
 * @author Sumun, M. Fadil
 * @brief Implementation of Black-Scholes formula
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "BlackScholesFormula.hpp"
#include <cmath>

BlackScholes::BlackScholes(double S, double K, double sigma, double r, double T) :
    S(S), K(K), sigma(sigma), r(r), T(T) {}

double BlackScholes::CalculateCallOptionPrice() const
{
    double D1 = d1();
    double D2 = d2();

    return S*N(D1) - K*exp(-r*T)*N(D2);
}

double BlackScholes::d1() const
{
    return (log(S/K) + (r+0.5*sigma*sigma)*T) / (sigma*sqrt(T));
}

double BlackScholes::d2() const {
    return d1() - sigma * sqrt(T);
}

double BlackScholes::N(double x) {
    return 0.5 * (1 + erf(x / sqrt(2.0)));
}