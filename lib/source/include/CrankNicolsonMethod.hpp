#ifndef CRANKNICOLSONMETHOD_HPP
#define CRANKNICOLSONMETHOD_HPP

#include "ImplicitMethod.hpp"

class CNNMethod : public ImplicitScheme
{
    public:
        /**
         * @brief Construct a new CNNMethod object
         * 
         * @param PtrPDE_ 
         * @param imax_ 
         * @param jmax_ 
         */
        CNNMethod(ParabPDE* PtrPDE_, int imax_, int jmax_)
            : ImplicitScheme(PtrPDE_, imax_, jmax_) {}

        double A(int i, int j);
        double B(int i, int j);
        double C(int i, int j);
        double D(int i, int j);
        double E(int i, int j);
        double F(int i, int j);
        double G(int i, int j);
};

#endif /* CRANKNICOLSONMETHOD_HPP */
