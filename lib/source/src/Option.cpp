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

