/**
 * @file HeatEquation.hpp
 * @author Sumun, M. Fadil
 * @brief 
 * @version 0.1
 * @date 2024-03-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef HEATEQUATION_HPP
#define HEATEQUATION_HPP

#include "BlackScholesModel.hpp"
#include "Option.hpp"
#include "ParabolicPDE.hpp"

/**
 * @brief Heat equation class (special case of parabolic PDE)
 * 
 */
class HeatEq : public ParabPDE
{
    public:
        BSModel* PtrModel;
        Option* PtrOption;
        HeatEq(BSModel* PtrModel_, Option* PtrOption_);

        double a(double t, double x);
        double b(double t, double x);
        double c(double t, double x);
        double d(double t, double x);

        double f(double x);
        double fl(double t);
        double fu(double t);

        double Z(double t, double x);
        double V(double t, double u);
        double X(double t, double z);
        double U(double t, double v);

};

#endif /* HEATEQUATION_HPP */
