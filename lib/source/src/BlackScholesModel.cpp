/**
 * @file BlackScholesModel.cpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "BlackScholesModel.hpp"
#include <cmath>

// Constructor
BSModel::BSModel(double S0_, double r_, double sigma_) 
{
    S0 = S0_;
    r = r_;
    sigma = sigma_;
}

// To be implemented
void BSModel::GenerateSamplePath(double T, int m, SamplePath& S) {}

