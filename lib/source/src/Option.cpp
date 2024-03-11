/**
 * @file Option.cpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Option.hpp"
#include <cmath>

Put::Put(double K_, double T_, double zl_, double zu_) 
{
    K = K_; T = T_; zl = zl_; zu = zu_;
}

double Put::Payoff(double z)
{
    return (K>z) ? K-z : 0.0;
}

double Put::UpperCondition(BSModel* PtrModel, double t)
{
    return 0.0;
}

double Put::LowerCondition(BSModel* PtrModel, double t)
{
    return K*exp(-PtrModel->r*(T-t));
}

// To check implementation for Call class
Call::Call(double K_, double T_, double zl_, double zu_)
{
    K = K_; T = T_; zl = zl_; zu = zu_; 
}

double Call::Payoff(double z)
{
    return (z>K) ? z-K : 0.0;
}

double Call::UpperCondition(BSModel* PtrModel, double t)
{
    return zu-K*exp(-PtrModel->r*(T-t));
}

double Call::LowerCondition(BSModel* PtrModel, double t)
{
    return zl;
}

