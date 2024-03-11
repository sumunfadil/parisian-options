#ifndef IMPLICITMETHOD_HPP
#define IMPLICITMETHOD_HPP

#include "FiniteDifferenceMethod.hpp"
#include "Matrix.hpp"
#include "Visitor.hpp"

/**
 * @brief Implicit finite-difference scheme
 * 
 */
class ImplicitScheme : public FDMethod
{
    public:
        Visitor* visitor;
        /**
         * @brief Construct a new Implicit Scheme object
         * 
         * @param PtrPDE_ Pointer to Parabolic PDE
         * @param imax_ 
         * @param jmax_ 
         */
        ImplicitScheme(ParabPDE* PtrPDE_, int imax_, int jmax_);

        Vector A(int i, Vector q);
        Vector w(int i);

        virtual double A(int i, int j) = 0;
        virtual double B(int i, int j) = 0;
        virtual double C(int i, int j) = 0;
        virtual double D(int i, int j) = 0;
        virtual double E(int i, int j) = 0;
        virtual double F(int i, int j) = 0;
        virtual double G(int i, int j) = 0;

        Vector accept(Visitor* visitor, int i, Vector q);

        /**
         * @brief Solve PDE
         * 
         */
        void SolvePDE();
};

#endif /* IMPLICITMETHOD_HPP */
