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
#include <memory>

class BSEqLCP : public LCP, public BSEq
{
    public:

        // Smart pointers
        BSEqLCP(std::unique_ptr<BSModel> PtrModel, std::unique_ptr<Option> PtrOption)
            : BSEq(std::move(PtrModel), std::move(PtrOption)) {PtrPDE = this;}

        double g(double t, double z); 

};

#endif /* BLACKSCHOLESLCP_HPP */
