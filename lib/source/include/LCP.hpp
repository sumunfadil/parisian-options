/**
 * @file LCP.hpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef LCP_HPP
#define LCP_HPP

#include "ParabolicPDE.hpp"

/**
 * @brief Linear Complementary Problem (abstract class)
 * 
 */
class LCP
{
    public:
        ParabPDE* PtrPDE;
        virtual double g(double t, double x) = 0;
};

#endif /* LCP_HPP */
