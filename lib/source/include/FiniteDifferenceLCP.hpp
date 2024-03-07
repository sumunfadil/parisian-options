/**
 * @file FiniteDifferenceLCP.hpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef FINITEDIFFERENCELCP_HPP
#define FINITEDIFFERENCELCP_HPP

#include "FiniteDifferenceMethod.hpp"
#include "LCP.hpp"

/**
 * @brief Finite-difference LCP class
 * 
 */
class FDLCP
{
    public:
        LCP* PtrLCP;
        FDMethod* PtrFDMethod;

        double g(int i, int j);
};

#endif /* FINITEDIFFERENCELCP_HPP */
