/**
 * @file ExplicitLCP.hpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef EXPLICITLCP_HPP
#define EXPLICITLCP_HPP

#include "LCP.hpp"
#include "FiniteDifferenceLCP.hpp"
#include "ExplicitMethod.hpp"

/**
 * @brief Explicit LCP class
 * 
 */
class ExplicitLCP : public ExplicitMethod, public FDLCP
{
    public: 
        /**
         * @brief Construct a new Explicit L C P object
         * 
         * @param PtrLCP_ 
         * @param imax_ 
         * @param jmax_ 
         */
        ExplicitLCP(LCP* PtrLCP_, int imax_, int jmax_)
            : ExplicitMethod(PtrLCP_->PtrPDE, imax_, jmax_)
            {
                PtrLCP = PtrLCP_;
                PtrFDMethod = this;
            }

        void SolveLCP();
};

#endif /* EXPLICITLCP_HPP */
