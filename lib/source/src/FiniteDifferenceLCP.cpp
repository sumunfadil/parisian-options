/**
 * @file FiniteDifferenceLCP.cpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "FiniteDifferenceLCP.hpp"

double FDLCP::g(int i, int j)
        {
            return PtrLCP->g(PtrFDMethod->t(i), PtrFDMethod->x(j));
        }