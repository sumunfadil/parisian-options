/**
 * @file BlackScholesLCP.hpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BLACKSCHOLESLCP_HPP
#define BLACKSCHOLESLCP_HPP

#include "LCP.hpp"
#include "BlackScholesModel.hpp"
#include "Option.hpp"
#include "BlackScholesEquation.hpp"

class BSEqLCP : public LCP, public BSEq
{
    public:
        BSEqLCP(BSModel* PtrModel, Option* PtrOption)
            : BSEq(PtrModel, PtrOption) {PtrPDE = this;}

        double g(double t, double z); 

};

#endif /* BLACKSCHOLESLCP_HPP */
