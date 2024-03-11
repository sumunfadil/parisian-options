/**
 * @file BlackScholesEquation.cpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "BlackScholesEquation.hpp"
#include <cmath>

BSEq::BSEq(std::unique_ptr<BSModel> PtrModel_, std::unique_ptr<Option> PtrOption_)
    : PtrModel(std::move(PtrModel_)), PtrOption(std::move(PtrOption_))
{
    T = PtrOption->T;
    xl = PtrOption->zl;
    xu = PtrOption->zu;
} 


double BSEq::a(double t, double z)
{
    return -0.5*pow(PtrModel->sigma*z, 2.0);
}


double BSEq::b(double t, double z) 
{
    return -PtrModel->r*z;
}   

double BSEq::c(double t, double z)
{
    return PtrModel->r;
}

double BSEq::d(double t, double z)
{
    return 0.0;
}

double BSEq::f(double z)
{
    return PtrOption->Payoff(z);
}

double BSEq::fl(double t)
{
    return PtrOption->LowerCondition(PtrModel.get(), t);
}
    
double BSEq::fu(double t)
{
    return PtrOption->UpperCondition(PtrModel.get(), t);
}






