/**
 * @file Option.hpp
 * @author Sumun, M. Fadil
 * @brief Option class
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef OPTION_HPP
#define OPTION_HPP

#include "BlackScholesModel.hpp"

/**
 * @brief Option payoff class (abstract class)
 * 
 */
class Option
{
    public:
        double T, zl, zu;

        virtual double Payoff(double z) = 0;
        virtual double UpperCondition(BSModel* PtrModel, double t) = 0;
        virtual double LowerCondition(BSModel* PtrModel, double t) = 0;
};

/**
 * @brief Put class is a derived class
 * 
 */
class Put : public Option
{
    public:
        double K;

        /**
         * @brief Construct a new Put object
         * 
         * @param K_ 
         * @param T_ 
         * @param zl_ 
         * @param zu_ 
         */
        Put(double K_, double T_, double zl_, double zu_);

        double Payoff(double z);
        double UpperCondition(BSModel* PtrModel, double t);
        double LowerCondition(BSModel* PtrModel, double t);
};

#endif /* OPTION_HPP */
