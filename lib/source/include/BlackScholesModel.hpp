/**
 * @file BlackScholesModel.hpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BLACKSCHOLESMODEL_HPP
#define BLACKSCHOLESMODEL_HPP

using namespace std;
#include <vector>

typedef vector<double> SamplePath;

/**
 * @brief Black-Scholes model class
 * 
 */
class BSModel
{
    public:
        double S0, r, sigma;

        /**
         * @brief Construct a new BSModel object
         * 
         * @param S0_ Stock price
         * @param r_ Risk-free interest rate
         * @param sigma_ Volatility
         */
        BSModel(double S0_, double r_, double sigma_); 

        /**
         * @brief Generate a sample path with m points
         * 
         * @param T Maturity date
         * @param m Number of points
         * @param S Price vector
         */
        void GenerateSamplePath(double T, int m, SamplePath& S);

};

#endif /* BLACKSCHOLESMODEL_HPP */
