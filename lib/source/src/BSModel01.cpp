#include "BSModel01.hpp"
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

