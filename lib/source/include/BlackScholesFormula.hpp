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

/**
 * @brief BlackScholes class
 * 
 */
class BlackScholes
{
    private:
        double d1() const;
        double d2() const;
        static double N(double x);

    public:
        double S;           
        double K;           
        double sigma;       
        double r;           
        double T;           

        /**
         * @brief Construct a new Black Scholes object
         * 
         * @param S Stock price
         * @param K Strike price
         * @param sigma Volatility
         * @param r Risk-free interest rate
         * @param T Maturity date
         */
        BlackScholes(double S, double K, double sigma, double r, double T);

        /**
         * @brief Price of a European call option using the Black-Scholes formula
         * 
         * @return double Price of a European call price
         */
        double CalculateCallOptionPrice() const;
};

#endif /* BLACKSCHOLESFORMULA_HPP */
