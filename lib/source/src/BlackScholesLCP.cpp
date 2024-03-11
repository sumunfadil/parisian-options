/**
 * @file BlackScholesLCP.cpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "BlackScholesLCP.hpp"

double BSEqLCP::g(double t, double z)
{
    return PtrOption->Payoff(z);
}