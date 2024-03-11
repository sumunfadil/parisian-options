/**
 * @file HeatEquation.cpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "HeatEquation.hpp"

HeatEq::HeatEq(std::unique_ptr<BSModel> PtrModel_, std::unique_ptr<Option> PtrOption_)
    : PtrModel(std::move(PtrModel_)), PtrOption(std::move(PtrOption_))
{
    T = PtrOption->T;
    xl = X(0.0, PtrOption->zl);
    xu = X(0.0, PtrOption->zu);
}

double HeatEq::a(double t, double x)
{
    return -0.5;
}

double HeatEq::b(double t, double x)
{
    return 0.0;
}

double HeatEq::c(double t, double x)
{
    return 0.0;
}

double HeatEq::d(double t, double x)
{
    return 0.0;
}

double HeatEq::f(double x)
{
    return V(T, PtrOption->Payoff(Z(T,x)));
}

double HeatEq::fl(double t)
{
    return V(t, PtrOption->LowerCondition(PtrModel.get(), t));
}

double HeatEq::fu(double t)
{
    return V(t, PtrOption->UpperCondition(PtrModel.get(), t));
}

double HeatEq::Z(double t, double x)
{
    double r = PtrModel->r;
    double sigma = PtrModel->sigma;
    double S0 = PtrModel->S0;
    return S0*exp((r-0.5*sigma*sigma)*t + sigma*x);
}

double HeatEq::V(double t, double u)
{
    return exp(-PtrModel->r*t)*u;
}

double HeatEq::X(double t, double z)
{
    double r = PtrModel->r;
    double sigma = PtrModel->sigma;
    double S0 = PtrModel->S0;
    return (log(z/S0) - (r-0.5*sigma*sigma)*t)/sigma;
}

double HeatEq::U(double t, double v)
{
    return exp(PtrModel->r*t)*v;
}
