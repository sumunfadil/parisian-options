/**
 * @file BSModel.hpp
 * @author Sumun, M. Fadil
 * @brief Black-Scholes Model
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

class BSModel
{
    public:
        double S0, r, sigma;

        // Constructor
        BSModel(double S0_, double r_, double sigma_); 

        void GenerateSamplePath(double T, int m, SamplePath& S);

};

#endif /* BLACKSCHOLESMODEL_HPP */
