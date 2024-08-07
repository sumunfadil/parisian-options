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
 * @brief Option payoff class (abstract class). This Option class and subsequent 
 * derived classes are mainly used for defining boundary conditions (one terminal
 * condition and two boundary conditions)
 * 
 */
class Option
{
    public:
        double T, zl, zu;

        virtual double Payoff(double z) = 0;
        // Boundary conditions often make use of model parameters
        // TODO: Pass pointer to AssetModel class
        virtual double UpperCondition(BSModel* PtrModel, double t) = 0;
        virtual double LowerCondition(BSModel* PtrModel, double t) = 0;
};

/**
 * @brief European put class is a derived class
 * 
 */
class Put : public Option
{
    public:
        double K;

        /**
         * @brief Construct a new Put object
         * 
         * @param K_ Strike price
         * @param T_ Maturity date
         * @param zl_ Lower boundary value
         * @param zu_ Upper boundary value
         */
        Put(double K_, double T_, double zl_, double zu_);

        double Payoff(double z);
        double UpperCondition(BSModel* PtrModel, double t);
        double LowerCondition(BSModel* PtrModel, double t);
};

/**
 * @brief European call class is a derived class
 * 
 */
class Call : public Option
{
    public: 
        double K;

        /**
         * @brief Construct a new Call object
         * 
         * @param K_ 
         * @param T_ 
         * @param zl_ 
         * @param zu_ 
         */
        Call(double K_, double T_, double zl_, double zu_);

        double Payoff(double z);
        double UpperCondition(BSModel* PtrModel, double t);
        double LowerCondition(BSModel* PtrModel, double t);
};

// TODO: Define path-dependent options classes

#endif /* OPTION_HPP */
