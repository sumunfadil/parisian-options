/**
 * @file BlackScholesFormula.hpp
 * @author Sumun, M. Fadil
 * @brief Implementation of Black-Scholes Formula
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BLACKSCHOLESFORMULA_HPP
#define BLACKSCHOLESFORMULA_HPP

class BlackScholes
{
    private:
        double d1() const;
        double d2() const;
        static double N(double x);

    public:
        double S;           // Price of underlying
        double K;           // Strike price
        double sigma;       // Volatility
        double r;           // Risk-free rate
        double T;           // Maturity date

        // Constructor
        BlackScholes(double S, double K, double sigma, double r, double T);

        double CalculateCallOptionPrice() const;
};

#endif /* BLACKSCHOLESFORMULA_HPP */
