#ifndef THOMASALGORITHMVISITOR_HPP
#define THOMASALGORITHMVISITOR_HPP

#include "FiniteDifferenceMethod.hpp"
#include "ImplicitMethod.hpp"
#include "Visitor.hpp"

// Visitor design pattern

class ThomasAlgorithmVisitor : public Visitor 
{
    public:
        Vector visit(ImplicitScheme* method, int i, Vector q) override;
        Vector visit(CNNMethod* method, int i, Vector q) override;
};

#endif /* THOMASALGORITHMVISITOR_HPP */
